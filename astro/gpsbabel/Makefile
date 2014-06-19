# Created by: Laurent Courty
# $FreeBSD$

PORTNAME=	gpsbabel
PORTVERSION=	1.5.1
CATEGORIES=	astro geography
MASTER_SITES=	https://secure.ohos.nl/downloads/ \
		LOCAL/glebius

MAINTAINER=	dev2@heesakkers.info
COMMENT=	GPS file translating tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes

USES=		gettext
USE_QT4=	corelib linguist_build qmake_build
USE_GNOME=	glib20

PLIST_FILES=	bin/gpsbabel

CONFLICTS=	gpsbabel14-[0-9]*

.include <bsd.port.mk>
