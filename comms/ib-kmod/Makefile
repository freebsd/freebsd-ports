# New ports collection makefile for:	ib
# Date created:				27 February 2008
# Whom:					Tofig Suleymanov <tofig@freebsd.az>
#
# $FreeBSD$
#

PORTNAME=	ib
PORTVERSION=	1.0.2
CATEGORIES=	comms kld
MASTER_SITES=	http://www.freebsd.az/other/
PKGNAMESUFFIX=	-kmod

MAINTAINER=	tofig@freebsd.az
COMMENT=	Driver for the Kyocera UTU Iburst modem

MODULES_WITH_WORLD?=	yes
ONLY_FOR_ARCHS=	i386
SUB_FILES=	pkg-install pkg-deinstall pkg-message
SUB_LIST+=	KMODDIR=${KMODDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

KMODDIR?=	/boot/modules
PLIST_FILES=	"@cwd ${KMODDIR}" \
		if_ib.ko

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not build
.endif

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
	@${ECHO} "*************************************************"; \
	${ECHO} "This port requires the kernel source be available"; \
	${ECHO} "*************************************************"; \
	exit 1
.endif

do-install:
	@${INSTALL_KLD} ${WRKSRC}/src/sys/modules/ib/if_ib.ko ${KMODDIR}

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
