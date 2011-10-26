# New ports collection makefile for:    bug5
# Date created:                         25 April 2011
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bug5
PORTVERSION=	1.8
CATEGORIES=	chinese converters
MASTER_SITES=	https://github.com/buganini/${PORTNAME}/tarball/${PORTVERSION}/
DISTNAME=	buganini-${PORTNAME}-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	A Big5/GBK <-> UTF-8 translating layer in terminal

LICENSE=	BSD

LIB_DEPENDS=	bsdconv.6:${PORTSDIR}/converters/bsdconv

GITVERSION=	6f10dda
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/buganini-${PORTNAME}-${GITVERSION}

MAKE_ARGS=	PREFIX=${PREFIX}

PLIST_FILES=	bin/bug5

.include <bsd.port.mk>
