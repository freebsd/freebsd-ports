# New ports collection makefile for:	splashsetter
# Date created:				15 Januar 2004
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	splashsetter
PORTVERSION=	0.6.5
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://webonaut.com/distfiles/${PORTNAME}/

MAINTAINER=	klammer@webonaut.com
COMMENT=	Splash screen changer for GNOME

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_GNOME=	pygnome2

do-build:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' \
		${WRKSRC}/*.py
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${MKDIR} ${X11BASE}/share/gnome/pixmaps/${PORTNAME}/splash
	${MKDIR} ${X11BASE}/libexec/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${X11BASE}/libexec/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/*.py* \
		${X11BASE}/libexec/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${X11BASE}/share/gnome/applications/
	@${INSTALL_DATA} ${WRKSRC}/*.svg \
		${X11BASE}/share/gnome/pixmaps/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/*.png \
		${X11BASE}/share/gnome/pixmaps/${PORTNAME}/splash/
	@${LN} -sf ${X11BASE}/libexec/${PORTNAME}/${PORTNAME} \
		${X11BASE}/bin/${PORTNAME}

.include <bsd.port.mk>
