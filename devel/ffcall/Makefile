# New ports collection makefile for:   ffcall
# Date created:        21 February 2001
# Whom:                jagapen@home.com
#
# $FreeBSD$
#

PORTNAME=	ffcall
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=  ftp://ftp.santafe.edu/pub/gnu/
MASTER_SITES=	${MASTER_SITE_GNUSTEP} \
		ftp://ftp.gnustep.org/pub/gnustep/libs/
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Foreign function call libraries

USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
NOT_FOR_ARCHS=	sparc64

MAN3=		avcall.3 callback.3 trampoline.3 trampoline_r.3 vacall.3
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

.include <bsd.port.post.mk>
