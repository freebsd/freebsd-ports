# ex:ts=8
# Ports collection makefile for:	divxcalc
# Date created:			Mar 21, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	divxcalc
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://imagef1.net.nz/divxcalc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DivX Calculator

USE_BZIP2=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:15:env autoconf:253:env
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

PLIST_FILES=	bin/divxcalc

pre-configure:
	@cd ${WRKSRC} && ${GMAKE} -f admin/Makefile.common

.include <bsd.port.mk>
