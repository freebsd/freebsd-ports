# New ports collection makefile for:	sampleicc
# Date created:		2012-01-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sampleicc
PORTVERSION=	1.6.6
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20tar/SampleIcc-${PORTVERSION}/
DISTNAME=	SampleICC-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for reading, writing, manipulating, and applying ICC profiles

LICENSE=	ICC
LICENSE_NAME=	The ICC Software License, Version 0.2
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	auto-accept

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

.include <bsd.port.mk>
