# ex:ts=8
# Ports collection makefile for:	fribidi
# Date created:			Apr 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fribidi
PORTVERSION=	0.10.4
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Free Implementation of the Unicode Bidirectional Algorithm

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_LIBTOOL=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
