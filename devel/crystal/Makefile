# New ports collection makefile for:   crystal
# Date created:        Thu Feb 21 18:44:14 CST 2002
# Whom:                Kyle Martin
#
# $FreeBSD$
#

PORTNAME=	crystal
PORTVERSION=	0.92
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://sunsite.dk/projects/crystal/cs092/source/
DISTNAME=	cs92_001

MAINTAINER=	mkm@ieee.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/CS

pre-build:
	cd ${WRKSRC}; ${GMAKE} freebsd

.include <bsd.port.mk>
