# New ports collection makefile for:	libpci
# Date created:				June 14, 2003
# Whom:					Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=	libpci
PORTVERSION=	2.1.11
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.kerneled.com/freebsd/ports/ \
		ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		ftp://ftp.kernel.org/pub/software/utils/pciutils/
DISTNAME=	pciutils-${PORTVERSION}

MAINTAINER=	samy@kerneled.com
COMMENT=	PCI configuration space I/O made easy

USE_BZIP2=	yes
USE_GMAKE=	yes
NO_INSTALL_MANPAGES=	yes
INSTALLS_SHLIB=	yes
ALL_TARGET=	lib

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "              W  A  R  N  I  N  G"
	@${ECHO_MSG} "************************************************"
	@${ECHO_MSG} "* libpci requires that you have your kernel    *"
	@${ECHO_MSG} "* sources installed. If your kernel sources    *"
	@${ECHO_MSG} "* are somewhere other than /usr/src/sys, you   *"
	@${ECHO_MSG} "* may set the FREEBSD_SYS variable to the      *"
	@${ECHO_MSG} "* correct path.                                *"
	@${ECHO_MSG} "************************************************"
	@${ECHO_MSG} ""

post-build:
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/pci.h

do-install:
	@(${CP} ${WRKSRC}/lib/libpci.so ${PREFIX}/lib/libpci.so.2)
	@(${CP} ${WRKSRC}/lib/libpci.a  ${PREFIX}/lib/libpci.a)
	@(${LN} -sf ${PREFIX}/lib/libpci.so.2.1 ${PREFIX}/lib/libpci.so)
	@(${MKDIR} ${PREFIX}/include/pci)
	@(${CP} ${WRKSRC}/lib/pci.h ${PREFIX}/include/pci/pci.h)

.include <bsd.port.mk>
