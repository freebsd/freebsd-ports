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

USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/[[:alpha:]]//}

OPTIONS_DEFINE=	GUI PLUGIN DOCS
GUI_DESC=	Build FLTK based GUI
PLUGIN_DESC=	Build plugin used in DOOM engines
OPTIONS_SUB=	yes

PORTDOCS=	README.txt USAGE.txt

GUI_LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|CC=|CC\?=|; s|CFLAGS=|CFLAGS\+=|' \
		${WRKSRC}/Makefile ${WRKSRC}/Plugin_unx.mak

post-build:
.if ${PORT_OPTIONS:MGUI}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} -f GUI_unx.mak all
.endif
.if ${PORT_OPTIONS:MPLUGIN}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} -f Plugin_unx.mak all
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glbsp ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MGUI}
	${INSTALL_PROGRAM} ${WRKSRC}/glBSPX ${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MPLUGIN}
	${INSTALL_DATA} ${WRKSRC}/libglbsp.a ${STAGEDIR}${PREFIX}/lib
.endif
	${INSTALL_MAN} ${WRKSRC}/glbsp.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
