PORTNAME=	e93
PORTVERSION=	1.4.3
CATEGORIES=	editors tcl
MASTER_SITES=	http://www.sqrt.com/downloads/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl-based, programmer-oriented text editor
WWW=		http://www.e93.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		compiler:c11 tar:tgz tcl xorg
USE_XORG=	x11 xinerama xmu

MAKE_ENV=	TCL_INCLUDEDIR=${TCL_INCLUDEDIR} TCL_VERSION=${TCL_SHLIB_VER}

PORTDOCS=	README* TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS=|CFLAGS\+=|g' \
		${WRKSRC}/xgui/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e93 ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/e93lib
	cd ${WRKSRC}/e93lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/e93lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
