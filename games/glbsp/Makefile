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

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/[[:alpha:]]//}

OPTIONS_DEFINE=	GUI PLUGIN DOCS
GUI_DESC=	Build FLTK based GUI
PLUGIN_DESC=	Build plugin used in DOOM engines

MAN1=		glbsp.1
PORTDOCS=	README.txt USAGE.txt

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
LIB_DEPENDS+=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
PLIST_SUB=	GUI_VERSION=""
.else
PLIST_SUB=	GUI_VERSION="@comment "
.endif

.if ${PORT_OPTIONS:MPLUGIN}
PLIST_SUB+=	PLUGIN=""
.else
PLIST_SUB+=	PLUGIN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|CC=|CC\?=|; s|CFLAGS=|CFLAGS\+=|' \
		${WRKSRC}/Makefile ${WRKSRC}/Plugin_unx.mak

post-build:
.if ${PORT_OPTIONS:MGUI}
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC} -f GUI_unx.mak all
.endif
.if ${PORT_OPTIONS:MPLUGIN}
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC} -f Plugin_unx.mak all
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glbsp ${PREFIX}/bin
.if ${PORT_OPTIONS:MGUI}
	${INSTALL_PROGRAM} ${WRKSRC}/glBSPX ${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MPLUGIN}
	${INSTALL_DATA} ${WRKSRC}/libglbsp.a ${PREFIX}/lib
.endif

	${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/|} ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
