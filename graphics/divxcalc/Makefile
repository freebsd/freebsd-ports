# ex:ts=8
# Ports collection makefile for:	divxcalc
# Date created:			Mar 21, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	divxcalc
PORTVERSION=	0.6
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.axljab.homelinux.org/pub/linux/divxcalc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DivX Calculator

USE_BZIP2=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
WANT_AUTOMAKE_VER=	15
WANT_AUTOCONF_VER=	253
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

PLIST_FILES=	bin/divxcalc

pre-configure:
	@cd ${WRKSRC} && ${GMAKE} -f admin/Makefile.common

.include <bsd.port.mk>
