# New ports collection makefile for:	splashsetter
# Date created:				15 Januar 2004
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	splashsetter
PORTVERSION=	0.6.5.3
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://webonaut.com/distfiles/${PORTNAME}/

MAINTAINER=	klammer@webonaut.com
COMMENT=	Splash screen changer for GNOME

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GNOME=	pygnome2 gnomeprefix

do-build:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/*.py
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/share/pixmaps/${PORTNAME}/splash
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${PREFIX}/libexec/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/*.py* \
		${PREFIX}/libexec/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/*.svg \
		${PREFIX}/share/pixmaps/${PORTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/splashsetter_icon.svg \
		${PREFIX}/share/pixmaps/${PORTNAME}.svg
	@${INSTALL_DATA} ${WRKSRC}/*.png \
		${PREFIX}/share/pixmaps/${PORTNAME}/splash/
	@${LN} -sf ${PREFIX}/libexec/${PORTNAME}/${PORTNAME} \
		${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
