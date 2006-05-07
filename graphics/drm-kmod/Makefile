# Ports collection makefile for:	drm-kmod
# Date created:				6 October 2001
# Whom:				Eric Anholt <eanholt@gladstone.uoregon.edu>
#
# $FreeBSD$
#

PORTNAME=	drm-kmod
PORTVERSION=	0.9.6
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	anholt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A FreeBSD kernel modules for 3d acceleration with the DRI

WRKSRC=		${WRKDIR}/${PORTNAME}

PKGMESSAGE=	${WRKSRC}/.MESSAGE

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386
.if ${OSVERSION} < 400006
BROKEN=		"FreeBSD before 4.1 is not supported"
.elif ${OSVERSION} > 500000
IGNORE=		"FreeBSD 5.0 has DRM supplied by the kernel"
.endif

.if defined(WITH_SMP)
CFLAGS+=	-DSMP -DAPIC_IO
.endif

pre-extract:
.if !defined(WITH_SMP)
	@${ECHO_MSG} "If you are using modules on an SMP system, use "make -DWITH_SMP" to get SMP locking"
	@${ECHO_MSG}
.endif
	@${ECHO_MSG} "If you don't want linux compatibility, use make -DDRM_NOLINUX"
	@${ECHO_MSG}

pre-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/drm.sh

pre-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > \
		${PKGMESSAGE}

do-install:
	${MKDIR} ${PREFIX}/lib/drm
	${INSTALL_PROGRAM} ${WRKSRC}/tdfx/tdfx.ko ${PREFIX}/lib/drm/
	${INSTALL_PROGRAM} ${WRKSRC}/mga/mga.ko ${PREFIX}/lib/drm/
	${INSTALL_PROGRAM} ${WRKSRC}/r128/r128.ko ${PREFIX}/lib/drm/
	${INSTALL_PROGRAM} ${WRKSRC}/radeon/radeon.ko ${PREFIX}/lib/drm/
	${INSTALL_PROGRAM} ${WRKSRC}/gamma/gamma.ko ${PREFIX}/lib/drm/

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/drm.sh ${PREFIX}/etc/rc.d/drm.sh.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
