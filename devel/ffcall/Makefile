# Created by: jagapen@home.com
# $FreeBSD$

PORTNAME=	ffcall
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.santafe.edu/pub/gnu/
MASTER_SITES+=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Foreign function call libraries

LICENSE=	GPLv2

USES=		gmake
GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-fPIC

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

.include <bsd.port.post.mk>
