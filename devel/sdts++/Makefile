# New ports collection makefile for:	sdts++
# Date created:         08 Feb 2000
# Whom:                 erik@habatech.no
#
# $FreeBSD$
#

PORTNAME=	sdts++
PORTVERSION=	1.3.1a
CATEGORIES=	devel
MASTER_SITES=	ftp://sdts.er.usgs.gov/pub/sdts/software/sdtsxx/ \
		http://lychnobite.org/sdts/ \
		ftp://boost.sourceforge.net/pub/boost/release/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} boost_1_23_0.tar.gz

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-boost=${WRKDIR}/boost_1_23_0

.include <bsd.port.mk>
