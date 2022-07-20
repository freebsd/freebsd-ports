PORTNAME=	ccache
PKGNAMESUFFIX?=	-memcached
PORTVERSION=	3.5.dev.20180926
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	LOCAL/bdrewery \
		GH

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Tool to minimize the compile time of C/C++ programs

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/GPL-3.0.txt

USE_GITHUB=	yes
GH_TAGNAME=	f7712082106bef085515f86ae47e7dbbd2a48b57

CONFLICTS_INSTALL?=	ccache ccache-static ccache-memcached-static

GNU_CONFIGURE=	yes

# Some files shared with devel/ccache
CCACHEDIR?=	${MASTERDIR}/../ccache

HOWTO=		ccache-howto-freebsd.txt
SUB_FILES=	${HOWTO} world-ccache pkg-message ccache-update-links.sh

PORTDOCS=	ccache-howto-freebsd.txt MANUAL.html MANUAL.adoc NEWS.adoc \
		NEWS.html

OPTIONS_DEFINE=	CLANGLINK LLVMLINK STATIC DOCS TINDERBOX
OPTIONS_DEFAULT=CLANGLINK LLVMLINK
OPTIONS_SUB=	yes

CLANGLINK_DESC=	Create clang compiler links if clang is installed
LLVMLINK_DESC=	Create llvm compiler links if llvm is installed
TINDERBOX_DESC=	Create tarball for tinderbox usage

USES=		autoreconf compiler gmake pkgconfig

CONFIGURE_ARGS+=	--enable-memcached
LIB_DEPENDS+=	libmemcached.so:databases/libmemcached
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

STATIC_CONFIGURE_ENABLE=	static
STATIC_LDFLAGS+=		-static
# Hack for libsasl2.a requiring HMAC_CTX_reset from hidden libntlm.a.
STATIC_LDFLAGS+= 		-L${LOCALBASE}/lib/sasl2

# While this works in theory it breaks due to install conflict in Poudriere
NO_CCACHE_DEPEND=	yes

.include <bsd.port.options.mk>

# Extra dependencies needed for generating manpage
.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${LOCALBASE}/bin/a2x:textproc/asciidoc
ALL_TARGET=	all docs
.endif

.include <bsd.port.pre.mk>

.  if ${COMPILER_TYPE} == clang
CPPFLAGS+=	-DCC_IS_CLANG
.  elif ${COMPILER_TYPE} == gcc
CPPFLAGS+=	-DCC_IS_GCC
.  endif

.include "${CCACHEDIR}/Makefile.compilers"

SUB_LIST+=	HOWTO="${HOWTO}"

post-build-TINDERBOX-on:
	@${MKDIR} ${WRKDIR}/tb/opt
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${WRKDIR}/tb/opt
.for l in ${CCACHE_COMPILERS}
	@${LN} -sf ${PORTNAME} ${WRKDIR}/tb/opt/${l}
.endfor
	@${TAR} -C ${WRKDIR}/tb -cpf ${WRKSRC}/${PORTNAME}.tar opt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccache ${STAGEDIR}${PREFIX}/bin
	# Memcached uses the 3.5 dev branch which requires asciidoc to generate
	# ccache.1.
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/ccache.1 ${STAGEDIR}${PREFIX}/man/man1
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/${CCLINKDIR}/world
	${INSTALL_SCRIPT} ${WRKDIR}/world-ccache \
		${STAGEDIR}${PREFIX}/${CCLINKDIR}/world/ccache
	${INSTALL_SCRIPT} ${WRKDIR}/ccache-update-links.sh \
		${STAGEDIR}${PREFIX}/bin/ccache-update-links

do-install-TINDERBOX-on:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.tar ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/MANUAL.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/MANUAL.adoc ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/NEWS.adoc ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/NEWS.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${HOWTO} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
