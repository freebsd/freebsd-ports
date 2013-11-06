# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure
PORTVERSION=	0.58
CATEGORIES=	lang
MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz ${PORTNAME}-docs-${PORTVERSION}.tar.gz
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Modern-style functional programming language

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr
BUILD_DEPENDS=	llvm>=3.2:${PORTSDIR}/devel/llvm
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_FILES=	pkg-message

USES=		gmake iconv pathfix pkgconfig
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libgmp-prefix=${LOCALBASE} --enable-release
USE_LDCONFIG=	yes

MAKE_ARGS+=	prefix=${PREFIX} mandir=${PREFIX}/man \
		CC=${CC} CFLAGS="${CFLAGS}" \
		CXX=${CXX} CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS+=-I${LOCALBASE}/include \
		LDFLAGS+=-L${LOCALBASE}/lib

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EMACS ETC EXAMPLES

EMACS_DESC=	Compile pure-mode.el with Emacs
ETC_DESC=	Copy Pure syntax highlighting to ${DATADIR}/etc

OPTIONS_DEFAULT=	ETC

OPTIONS_SUB=	yes

EMACS_CONFIGURE_ENABLE=		--with-elisp
EMACS_CONFIGURE_DISABLE=	--without-elisp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMACS}
USE_EMACS=	yes
MAKE_ARGS+=	emacs_prefix=${PREFIX}
.endif

.if ${OSVERSION} < 900014
SUB_LIST+=	NOCLANG=""
.else
SUB_LIST+=	NOCLANG="@comment "
.endif

# automatically disable readline support if editline support is available
.if exists(/usr/include/edit/readline/readline.h)
CONFIGURE_ARGS+=	--without-readline
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd
.endif

post-install:
.if ${PORT_OPTIONS:METC}
	@${MKDIR} ${STAGEDIR}${DATADIR}/etc/
	@(cd ${WRKSRC} && ${RM} -f etc/*.in && ${COPYTREE_SHARE} etc/ ${STAGEDIR}${DATADIR})
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKDIR}/${PORTNAME}-docs-${PORTVERSION} && ${RM} -f Makefile && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${LN} -sf ${DOCSDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/docs
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
