# ex:ts=8
# ports collection makefile for:	cproto
# Date created:				2000 Feb. 13
# Whom:					Abel Chow <abel_chow@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	cproto
PORTVERSION=	4.7c
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/cproto/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate C function prototypes and convert function definitions

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		cproto.1
PLIST_FILES=	bin/cproto

.include <bsd.port.mk>
