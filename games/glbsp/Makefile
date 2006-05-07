# New ports collection makefile for: glbsp
# Date created:		22 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	glbsp
PORTVERSION=	2.20
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/.//}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	BSP node builder for OpenGL ports of the DOOM game engine

.ifdef (WITH_GUI_VERSION)
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
.endif

USE_GMAKE=	yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" X11BASE="${X11BASE}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/[[:alpha:]]//}

MAN1=		glbsp.1
PORTDOCS=	README.txt USAGE.txt

.if !defined (WITH_GUI_VERSION)
PLIST_SUB=	GUI_VERSION="@comment "
.else
PLIST_SUB=	GUI_VERSION=""
.endif

.if !defined (WITH_PLUGIN)
PLIST_SUB+=	PLUGIN="@comment "
.else
PLIST_SUB+=	PLUGIN=""
.endif

pre-everything::
.ifndef (WITH_GUI_VERSION)
	@${ECHO_CMD} "Define WITH_GUI_VERSION=yes to build FLTK based GUI version"
.endif
.ifndef (WITH_PLUGIN)
	@${ECHO_CMD} "Define WITH_PLUGIN=yes to build plugin version of glBSP used in DOOM engines"
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|CC=|CC\?=|; s|CFLAGS=|CFLAGS\+=|' \
		${WRKSRC}/Makefile ${WRKSRC}/Plugin_unx.mak

post-build:
.ifdef (WITH_GUI_VERSION)
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC} -f GUI_unx.mak all
.endif
.ifdef (WITH_PLUGIN)
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC} -f Plugin_unx.mak all
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glbsp ${PREFIX}/bin
.ifdef (WITH_GUI_VERSION)
	${INSTALL_PROGRAM} ${WRKSRC}/glBSPX ${PREFIX}/bin
.endif
.ifdef (WITH_PLUGIN)
	${INSTALL_DATA} ${WRKSRC}/libglbsp.a ${PREFIX}/lib
.endif

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/|} ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
