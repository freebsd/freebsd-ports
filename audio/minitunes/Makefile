# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	minitunes
PORTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://flavio.tordini.org/files/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Just another music player

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		qmake qt:4
USE_QT=		dbus gui moc_build network phonon rcc_build \
		sql uic_build xml
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
