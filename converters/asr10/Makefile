# Created by: M.Indlekofer@gmx.de
# $FreeBSD$

PORTNAME=      asr10
PORTVERSION=   1.0
CATEGORIES=    converters
MASTER_SITES=  http://members.tripod.com/kmi9000/files/

MAINTAINER=    M.Indlekofer@gmx.de
COMMENT=       Access to Ensoniq EPS/EPS+/ASR devices and image files

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/wav2asr ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.template ${PREFIX}/libdata/

.include <bsd.port.mk>
