# New ports collection makefile for:	sdts++
# Date created:         08 Feb 2000
# Whom:                 erik@habatech.no
#
# $FreeBSD$
#

PORTNAME=	sdts++
PORTVERSION=	1.3.1a
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://sdts.er.usgs.gov/pub/sdts/software/sdtsxx/:site1 \
		http://lychnobite.org/sdts/:site1 \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	boost
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:site1 \
		boost_1_27_0${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-boost=${WRKDIR}/boost_1_27_0

.include <bsd.port.mk>
