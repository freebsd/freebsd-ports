# New ports collection makefile for:	vertex
# Date created:				1 June 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vertex
PORTVERSION=	0.0.1d
CATEGORIES=	graphics
MASTER_SITES=	ftp://wolfpack.twu.net/users/wolfpack/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea \
		Imlib.5:${PORTSDIR}/graphics/imlib \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${DISTNAME}/vertex

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GTK=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKEFILE=	Makefile.Linux

.include <bsd.port.mk>
