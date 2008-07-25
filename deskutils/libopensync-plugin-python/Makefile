# New ports collection makefile for:	libopensync-plugin-python
# Date created:				18 July 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	libopensync-plugin-python
PORTVERSION=	0.22
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	webmaster@kibab.com
COMMENT=	Python plugin for the OpenSync framework

LIB_DEPENDS=	opensync.0:${PORTSDIR}/devel/libopensync022

CONFLICTS=	libopensync-plugin-python-devel-[0-9]*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes

.include <bsd.port.mk>
