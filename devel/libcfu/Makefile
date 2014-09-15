# $FreeBSD$

PORTNAME=	libcfu
DISTVERSION=	0.04a
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Simple library of tools for developing multithreaded software

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	crees
GH_COMMIT=	947dba4
GH_TAGNAME=	947dba4

USES=		makeinfo pkgconfig pathfix libtool
PATHFIX_MAKEFILEIN=	Makefile.am

USE_AUTOTOOLS=	autoconf autoheader automake aclocal libtoolize
AUTOMAKE_ARGS=	--add-missing
INFO=		${PORTNAME}

.include <bsd.port.mk>
