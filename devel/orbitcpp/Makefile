# New ports collection makefile for:	orbitcpp
# Date created:		30 August 2001
# Whom:	      	  Thomas Hentschel <thomas at hentschel dot net>
#
# $FreeBSD$
#

PORTNAME=	orbitcpp
PORTVERSION=	1.3.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ bindings for ORBit, a CORBA 2.2-compliant ORB

LIB_DEPENDS=	ORBit-2.0:${PORTSDIR}/devel/ORBit2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
