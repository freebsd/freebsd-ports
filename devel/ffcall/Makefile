# New ports collection makefile for:   ffcall
# Date created:        21 February 2001
# Whom:                jagapen@home.com
#
# $FreeBSD$
#

PORTNAME=	ffcall
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.santafe.edu/pub/gnu/
MASTER_SITES+=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Foreign function call libraries

LICENSE=	GPLv2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

MAN3=		avcall.3 callback.3 trampoline.3 trampoline_r.3 vacall.3
MANCOMPRESSED=	no
CFLAGS+=	-fPIC

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

.include <bsd.port.post.mk>
