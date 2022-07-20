PORTNAME=	ccache
PORTVERSION=	3.7.12
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ccache/ccache/releases/download/v${DISTVERSION}/ \
		LOCAL/bdrewery

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Tool to minimize the compile time of C/C++ programs

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/GPL-3.0.txt

CONFLICTS_INSTALL?=	ccache-static ccache-memcached ccache-memcached-static

GNU_CONFIGURE=	yes

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

USES=		compiler

STATIC_CONFIGURE_ENABLE=	static
STATIC_LDFLAGS+=		-static

# Support WITH_CCACHE_BUILD but don't depend on it.
NO_CCACHE_DEPEND=	yes

.include <bsd.port.pre.mk>

.  if ${COMPILER_TYPE} == clang
CPPFLAGS+=	-DCC_IS_CLANG
.  elif ${COMPILER_TYPE} == gcc
CPPFLAGS+=	-DCC_IS_GCC
.  endif

.include "${MASTERDIR}/Makefile.compilers"

SUB_LIST+=	HOWTO="${HOWTO}"

post-patch:
	@${REINPLACE_CMD} \
	    -e 's,_XOPEN_SOURCE 600,_XOPEN_SOURCE 700,' \
	    -e 's,_POSIX_C_SOURCE 200112L,_POSIX_C_SOURCE 200809L,' \
	    ${WRKSRC}/configure

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
	${INSTALL_MAN} ${WRKSRC}/doc/ccache.1 ${STAGEDIR}${PREFIX}/man/man1
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
