# New ports collection makefile for:	resid
# Date created:				6 October 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	resid
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	audio emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sidplay2
DISTNAME=	${PORTNAME}-${PORTVERSION}-p1
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-shared
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
