# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	converseen
PORTVERSION=	0.6.8
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Converseen/Converseen%200.6/

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Easy to use graphics conversion utility

LIB_DEPENDS=	libMagick++.so:${PORTSDIR}/graphics/ImageMagick

USE_BZIP2=	yes
USES=		cmake gettext iconv
USE_QT4=	corelib gui linguist_build moc_build qmake_build \
		rcc_build uic_build

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/converseen

.include <bsd.port.mk>
