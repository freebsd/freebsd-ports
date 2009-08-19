# New ports collection makefile for:	libpci
# Date created:				June 14, 2003
# Whom:					Samy Al Bahra <samy@kerneled.org>
#
# $FreeBSD$
#

PORTNAME=	libpci
PORTVERSION=	2.2.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		${MASTER_SITE_KERNEL_ORG} \
		ftp://metalab.unc.edu/pub/Linux/hardware/
MASTER_SITE_SUBDIR=	software/utils/pciutils
DISTNAME=	pciutils-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PCI configuration space I/O made easy

USE_GMAKE=	yes
NO_INSTALL_MANPAGES=	yes
USE_LDCONFIG=	yes
MAKE_ENV=	LANG=C
ALL_TARGET=	lib/libpci.a

post-build:
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/pci.h

do-install:
	@(${INSTALL_DATA} ${WRKSRC}/lib/libpci.so ${PREFIX}/lib/libpci.so.2)
	@(${INSTALL_DATA} ${WRKSRC}/lib/libpci.a ${PREFIX}/lib/libpci.a)
	@(${LN} -sf ${PREFIX}/lib/libpci.so.2 ${PREFIX}/lib/libpci.so)
	@(${MKDIR} ${PREFIX}/include/pci)
	@(${INSTALL_DATA} ${WRKSRC}/lib/config.h ${PREFIX}/include/pci/config.h)
	@(${INSTALL_DATA} ${WRKSRC}/lib/header.h ${PREFIX}/include/pci/header.h)
	@(${INSTALL_DATA} ${WRKSRC}/lib/pci.h ${PREFIX}/include/pci/pci.h)
	@(${INSTALL_DATA} ${WRKSRC}/lib/types.h ${PREFIX}/include/pci/types.h)

.include <bsd.port.mk>
