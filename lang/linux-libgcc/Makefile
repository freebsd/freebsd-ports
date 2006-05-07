# New ports collection makefile for:	linux-libgcc
# Date created:				25 Nov 2005
# Whom:					jylefort@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libgcc
DISTVERSION=	3.4.4-2
PORTREVISION=	2
CATEGORIES=	lang linux
MASTER_SITE_SUBDIR=	updates/3/${LINUX_RPM_ARCH}/
DISTNAME=	${PORTNAME}-${DISTVERSION}.fc3

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Linux libgcc support library

CONFLICTS=	linux_base-fc3-*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
AUTOMATIC_PLIST=yes
SRC_DISTFILES=	gcc-3.4.4-2.fc3.src.rpm

# Do not conflict with linux_base's libgcc: install in /lib/libgcc
# (note that we do not set INSTALLS_SHLIB because we must prepend
# /lib/libgcc to /etc/ld.so.conf before running ldconfig, which we do
# in pkg-install).

post-extract:
	@${MKDIR} ${WRKSRC}/lib/libgcc
	@${MV} -f ${WRKSRC}/lib/libgcc_s* ${WRKSRC}/lib/libgcc

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
