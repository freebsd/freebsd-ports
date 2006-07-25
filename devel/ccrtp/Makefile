# New ports collection makefile for:	ccrtp
# Date created:		2006-04-22
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	ccrtp
PORTVERSION=	1.4.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Implementation of the real-time transport protocol

LIB_DEPENDS=	ccgnu2-1.4.0:${PORTSDIR}/devel/commoncpp

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_GCC=	3.4+
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INFO=	ccrtp

.include <bsd.port.mk>
