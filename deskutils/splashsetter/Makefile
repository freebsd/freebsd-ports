# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$

PORTNAME=	splashsetter
PORTVERSION=	0.6.5.3
PORTREVISION=	6
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://webonaut.com/distfiles/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Splash screen changer for GNOME

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GNOME=	pygnome2 gnomeprefix

do-build:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/*.py
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}/splash
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.py \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/*.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/splashsetter_icon.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.svg
	${INSTALL_DATA} ${WRKSRC}/*.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}/splash
	${LN} -sf ${PREFIX}/libexec/${PORTNAME}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX}/libexec/${PORTNAME} -f libexec/${PORTNAME}
	cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O -m compileall \
		-d ${PREFIX}/libexec/${PORTNAME} -f libexec/${PORTNAME}

.include <bsd.port.mk>
