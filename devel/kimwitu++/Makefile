# ex:ts=8
# New ports collection makefile for:	kimwitu++
# Date created:			Apr 23, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kimwitu++
PORTVERSION=	2.3.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://site.informatik.hu-berlin.de/kimwitu++/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for processing trees (i.e. terms)

USE_BISON=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		kc++.1
PLIST_FILES=	bin/kc++

.include <bsd.port.mk>
