# ex:ts=8
# Ports collection makefile for:	nova
# Date created:			Apr 16, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nova
PORTVERSION=	0.4
PORTREVISION=	11
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Integrated Observational Environment for amateur astronomers

LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		gtkmm-2.0.6:${PORTSDIR}/x11-toolkits/gtkmm20 \
		gnomemm-2.0.1:${PORTSDIR}/x11/libgnomemm \
		glademm-2.0.1:${PORTSDIR}/devel/libglademm \
		gconfmm-2.0.1:${PORTSDIR}/devel/gconfmm \
		gnomecanvasmm-2.0.1:${PORTSDIR}/graphics/libgnomecanvasmm \
		gnomeuimm-2.0.1:${PORTSDIR}/x11-toolkits/libgnomeuimm \
		xml\\+\\+-1.0.1:${PORTSDIR}/textproc/libxml++ \
		nova:${PORTSDIR}/astro/libnova
RUN_DEPENDS=	${LOCALBASE}/share/nova/catalogs/sky2000.ncd:${PORTSDIR}/astro/sky2000

USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--datadir=${DATADIR}

.include <bsd.port.mk>
