# Created by: tdb
# $FreeBSD$

PORTNAME=	libmowgli2
PORTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	http://github.com/atheme/libmowgli-2/archive/
DISTNAME=	libmowgli-${DISTVERSION}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Development framework for C

WRKSRC=		${WRKDIR}/libmowgli-2-libmowgli-${DISTVERSION}

USES=		gmake pathfix
PATHFIX_MAKEFILEIN=	Makefile
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
