# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	opencbm-plugin-xa1541
PORTVERSION=	${OCBM_VERSION}
CATEGORIES=	comms archivers

PATCHFILES=	12ef17d4cf78903c9c52d7a348a816424d549b89.diff \
		ca4c06e7430caf3b2296d4e1e00051fff015fc53.diff

MAINTAINER=	felix@palmen-it.de
COMMENT=	OpenCBM plugin for parallel-port cables

LICENSE=	GPLv2

BUILD_DEPENDS=	cc65:devel/cc65
RUN_DEPENDS=	opencbm=${PORTVERSION}:comms/opencbm \
		opencbm-kmod=${PORTVERSION}:comms/opencbm-kmod

USES=		gmake
USE_LDCONFIG=	yes

MAKE_ARGS=	CC=cc SUBDIRS_PLUGIN_XA1541=opencbm/lib/plugin/xa1541
MAKEFILE=	LINUX/Makefile
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	plugin-xa1541
INSTALL_TARGET=	install-plugin-xa1541

post-install:
	${STRIP_CMD} ${STAGEDIR}${PLUGINBASENAME}xa1541.so.${OCBM_LIBVERSION}
	@${RM} ${STAGEDIR}${PREFIX}/etc/opencbm.conf.d/00opencbm.conf
	@${RM} ${STAGEDIR}${PREFIX}/etc/opencbm.conf

.include "../opencbm/Makefile.inc"

.include <bsd.port.mk>
