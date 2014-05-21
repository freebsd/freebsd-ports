# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	converseen
PORTVERSION=	0.7.1.1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Converseen/Converseen%200.7/

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Easy to use graphics conversion utility

LIB_DEPENDS=	libMagick++.so:${PORTSDIR}/graphics/ImageMagick

USES=		cmake gettext iconv tar:bzip2
USE_QT4=	corelib gui linguist_build moc_build qmake_build \
		rcc_build uic_build

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/converseen

.include <bsd.port.mk>
