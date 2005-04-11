# New ports collection makefile for:   libtar
# Date created:        06 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libtar
PORTVERSION=	1.2.11
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.feep.net/pub/software/libtar/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for manipulating POSIX and GNU tar files

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>
.include "files/manpages"
.include <bsd.port.post.mk>
