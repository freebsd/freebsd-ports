PORTNAME=	opencbm-plugin-xa1541
PORTVERSION=	${OCBM_VERSION}
CATEGORIES=	comms archivers

PATCHFILES=	077611e1ec27b52081c45c1702ff3812233fdd5e.diff \
		dfa9dd172e2843a661cdb6cdba09d1c6c2c1b35e.diff \
		a5fb83548b0ed54372d7615118c8ec9ba338bb9b.diff

MAINTAINER=	felix@palmen-it.de
COMMENT=	OpenCBM plugin for parallel-port cables

LICENSE=	GPLv2

BUILD_DEPENDS=	cc65:devel/cc65
RUN_DEPENDS=	opencbm=${PORTVERSION}:comms/opencbm \
		opencbm-kmod=${PORTVERSION}:comms/opencbm-kmod

USES=		gmake pkgconfig
USE_LDCONFIG=	yes

MAKE_ARGS=	CC="${CC}" SUBDIRS_PLUGIN_XA1541=opencbm/lib/plugin/xa1541
MAKEFILE=	LINUX/Makefile
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	plugin-xa1541
INSTALL_TARGET=	install-plugin-xa1541

post-install:
	${STRIP_CMD} ${STAGEDIR}${PLUGINBASENAME}xa1541.so.${OCBM_VERSION}
	@${RM} ${STAGEDIR}${PREFIX}/etc/opencbm.conf.d/00opencbm.conf
	@${RM} ${STAGEDIR}${PREFIX}/etc/opencbm.conf

.include "../opencbm/Makefile.inc"

.include <bsd.port.mk>
