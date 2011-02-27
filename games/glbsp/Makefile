# New ports collection makefile for: glbsp
# Date created:		22 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

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

OPTIONS=	GUI "Build FLTK based GUI" off \
		PLUGIN "Build plugin used in DOOM engines" off

MAN1=		glbsp.1
PORTDOCS=	README.txt USAGE.txt

.include <bsd.port.pre.mk>

.ifdef (WITH_GUI)
LIB_DEPENDS+=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
PLIST_SUB=	GUI_VERSION=""
.else
PLIST_SUB=	GUI_VERSION="@comment "
.endif

.ifdef (WITH_PLUGIN)
PLIST_SUB+=	PLUGIN=""
.else
PLIST_SUB+=	PLUGIN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|CC=|CC\?=|; s|CFLAGS=|CFLAGS\+=|' \
		${WRKSRC}/Makefile ${WRKSRC}/Plugin_unx.mak

post-build:
.ifdef (WITH_GUI)
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC} -f GUI_unx.mak all
.endif
.ifdef (WITH_PLUGIN)
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC} -f Plugin_unx.mak all
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glbsp ${PREFIX}/bin
.ifdef (WITH_GUI)
	${INSTALL_PROGRAM} ${WRKSRC}/glBSPX ${PREFIX}/bin
.endif
.ifdef (WITH_PLUGIN)
	${INSTALL_DATA} ${WRKSRC}/libglbsp.a ${PREFIX}/lib
.endif

	${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/|} ${MANPREFIX}/man/man1
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
