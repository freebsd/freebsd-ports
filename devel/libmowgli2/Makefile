# Created by: tdb
# $FreeBSD$

PORTNAME=	libmowgli2
PORTVERSION=	2.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Development framework for C

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	atheme
GH_PROJECT=	libmowgli-2

GNU_CONFIGURE=	yes
USES=		gmake pathfix ssl
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes

.include <bsd.port.mk>
