# New ports collection makefile for:	sdts++
# Date created:         08 Feb 2000
# Whom:                 erik@habatech.no
#
# $FreeBSD$
#

PORTNAME=	sdts++
PORTVERSION=	1.5.1
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://thor-f5.er.usgs.gov/sdts/sdtsxx/ \
		http://lychnobite.org/sdts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for SDTS related development

BUILD_DEPENDS=	${LOCALBASE}/lib/libboost_thread.so:${PORTSDIR}/devel/boost
RUN_DEPENDS=	${LOCALBASE}/lib/libboost_thread.so:${PORTSDIR}/devel/boost

USE_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
.endif

.include <bsd.port.post.mk>
