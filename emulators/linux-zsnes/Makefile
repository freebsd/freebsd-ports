# New ports collection makefile for:	linux-zsnes
# Date created:			22 June 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	zsnes
PORTVERSION=	1.36
CATEGORIES=	emulators linux
MASTER_SITES=	http://newrpms.sunsite.dk/apt/redhat/en/i386/9.0/RPMS.newrpms/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION}-3.i386
EXTRACT_SUFX=	.rpm
EXTRACT_ONLY=

MAINTAINER=	tlp@liquidx.org
COMMENT=	Linux binary version of the x86 only SNES emulator

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
RUN_DEPENDS=	${LINUXBASE}/lib/libc-2.3.2.so:${PORTSDIR}/emulators/linux_base-8 \
		${LINUXBASE}/usr/X11R6/lib/libXi.so.6:${PORTSDIR}/x11/linux-XFree86-libs \
		${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri \
		${LINUXBASE}/usr/lib/libpng12.so.0:${PORTSDIR}/graphics/linux-png \
		${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12

ONLY_FOR_ARCHS=	i386
DIST_SUBDIR=	rpm
NO_BUILD=	yes

MANCOMPRESSED=	yes
MAN1=		linux-zsnes.1
PLIST_FILES=	bin/linux-zsnes

STRIP=

post-extract:
	cd ${WRKDIR}; rpm2cpio.pl ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} | ${CPIO} -id --quiet

do-install:
	${INSTALL_MAN} ${WRKDIR}/usr/share/man/man1/zsnes.1.gz ${PREFIX}/man/man1/linux-zsnes.1.gz
	${INSTALL_PROGRAM} ${WRKDIR}/usr/bin/zsnes ${PREFIX}/bin/linux-zsnes

.include <bsd.port.mk>
