# New ports collection makefile for:    xmfract
# Date created:         Thu Aug  1 09:10:22 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xmfract
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The dos based 'fractint' with an X/Motif front end

USE_MOTIF=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-editres	\
	--with-motif="motif_includes=${X11BASE}/include motif_libraries=${X11BASE}/lib"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
USE_GCC=4.2+
IGNORE=		fails to run with: XCreateImage failed
.endif

.include <bsd.port.post.mk>
