PORTNAME=	airsaned
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2-54
DISTVERSIONSUFFIX=	-g433b762
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	fbsd@opal.com
COMMENT=	Apple AirScan compatible SANE web frontend

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libpng.so:graphics/png \
		libsane.so:graphics/sane-backends

USES=		cmake compiler:c++11-lib jpeg localbase:ldflags
USE_GITHUB=	yes

RC_SUBR=	freebsd/${PORTNAME}

GH_ACCOUNT=	SimulPiscator
GH_PROJECT=	AirSane

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    ${PATCH_WRKSRC}/server/server.cpp

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${RC_SUBR} >${STAGEDIR}${PREFIX}/etc/rc.d/${PORTNAME}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/etc/rc.d/${PORTNAME}
	@${MV} ${STAGEDIR}${PREFIX}/etc/airsane/ignore.conf ${STAGEDIR}${PREFIX}/etc/airsane/ignore.conf.sample
	@${MV} ${STAGEDIR}${PREFIX}/etc/airsane/options.conf ${STAGEDIR}${PREFIX}/etc/airsane/options.conf.sample

.include <bsd.port.mk>
