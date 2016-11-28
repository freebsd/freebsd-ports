# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	glbsp
PORTVERSION=	2.20
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSP node builder for OpenGL ports of the DOOM game engine

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/[[:alpha:]]//}

PORTDOCS=	README.txt USAGE.txt

OPTIONS_DEFINE=	GUI PLUGIN DOCS
OPTIONS_SUB=	yes
PLUGIN_DESC=	Build plugin used in DOOM engines
GUI_DESC=	Build FLTK based GUI
GUI_LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|CC=|CC\?=|; s|CFLAGS=|CFLAGS\+=|' \
		${WRKSRC}/Makefile ${WRKSRC}/Plugin_unx.mak

post-build-GUI-on:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} -f GUI_unx.mak all

post-build-PLUGIN-on:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} -f Plugin_unx.mak all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glbsp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/glbsp.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-GUI-on:
	${INSTALL_PROGRAM} ${WRKSRC}/glBSPX ${STAGEDIR}${PREFIX}/bin

do-install-PLUGIN-on:
	${INSTALL_DATA} ${WRKSRC}/libglbsp.a ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
