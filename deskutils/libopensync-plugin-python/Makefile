# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libopensync-plugin-python
PORTVERSION=	0.22
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	webmaster@kibab.com
COMMENT=	Python plugin for the OpenSync framework

LIB_DEPENDS=	libopensync.so:${PORTSDIR}/devel/libopensync022

CONFLICTS=	libopensync-plugin-python-devel-[0-9]*

USES=		pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
