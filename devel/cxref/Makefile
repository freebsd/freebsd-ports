# New ports collection makefile for:	cxref
# Date created:		23 October 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cxref
PORTVERSION=	1.5e
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.demon.co.uk/pub/unix/tools/
MASTER_SITE_SUBDIR=	devel/lang/c
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C program cross-referencing & documentation tool

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		cxref.1 cxref-query.1

.include <bsd.port.mk>
