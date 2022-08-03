PORTNAME=	opencbm-plugin-xa1541
PORTVERSION=	${OCBM_VERSION}
CATEGORIES=	comms archivers

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	OpenCBM plugin for parallel-port cables

LICENSE=	GPLv2

BUILD_DEPENDS=	cc65:devel/cc65
RUN_DEPENDS=	opencbm=${PORTVERSION}:comms/opencbm \
		opencbm-kmod=${PORTVERSION}:comms/opencbm-kmod

USES=		gmake pkgconfig
USE_LDCONFIG=	yes

ALL_TARGET=	plugin-xa1541
INSTALL_TARGET=	install-plugin-xa1541

post-install:
	${STRIP_CMD} ${STAGEDIR}${PLUGINBASENAME}xa1541.so.${OCBM_VERSION}
	@${RM} ${STAGEDIR}${PREFIX}/etc/opencbm.conf.d/00opencbm.conf
	@${RM} ${STAGEDIR}${PREFIX}/etc/opencbm.conf

.include "../opencbm/Makefile.inc"

.include <bsd.port.mk>
