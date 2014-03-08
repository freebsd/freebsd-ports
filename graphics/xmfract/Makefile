# Created by: Eric L. Hernes <erich@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmfract
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	XCONTRIB/graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Popular DOS fractal drawing program with X11/Motif frontend

LICENSE=	GPLv2

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
USES=		motif
USE_AUTOTOOLS=	aclocal autoconf
ACLOCAL_ARGS=	# none
CONFIGURE_ARGS=	--with-editres \
		--with-motif="motif_includes=${LOCALBASE}/include motif_libraries=${LOCALBASE}/lib"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
IGNORE=		fails to run with: XCreateImage failed
.endif

.include <bsd.port.post.mk>
