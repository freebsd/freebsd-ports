# New ports collection makefile for:	gdnsd
# Date created:			Tue May 15, 2012
# Whom:				Stefan Caunter <stef@scaleengine.com>
#
# $FreeBSD$
#

PORTNAME=	gdnsd
PORTVERSION=	1.6.8
CATEGORIES=	dns
MASTER_SITES=	https://github.com/blblack/gdnsd/downloads/ \
		http://gdnsd.scaleengine.net/gdnsd/

MAINTAINER=	ports@scaleengine.com
COMMENT=	Authoritative-only GeoIP-aware DNS server

LICENSE=	GPLv3

OPTIONS_DEFINE=	GEOIP

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		gdnsd_geoip_test.1
MAN3=		gdnsd-plugin-api.3
MAN5=		gdnsd.config.5 gdnsd.zonefile.5
MAN8=		gdnsd.8 gdnsd-plugin-simplefo.8 gdnsd-plugin-multifo.8 \
		gdnsd-plugin-metafo.8 gdnsd-plugin-geoip.8 \
		gdnsd-plugin-weighted.8
MANCOMPRESSED=	no

USE_RC_SUBR=	gdnsd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWITH_GEOIP}
RUN_DEPENDS+=	${LOCALBASE}/share/GeoIP/GeoIP.dat:${PORTSDIR}/net/GeoIP
.endif

post-install:
	${CP} ${WRKDIR}/${DISTNAME}/docs/config.example ${ETCDIR}/config-dist
	@if [ ! -f ${ETCDIR}/config ]; then \
		${CP} -p ${WRKDIR}/${DISTNAME}/docs/config.example ${ETCDIR}/config ; \
	fi
	${CP} ${WRKDIR}/${DISTNAME}/docs/example.com ${ETCDIR}/example.com

.include <bsd.port.mk>
