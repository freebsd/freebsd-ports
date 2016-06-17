# Created by: jrm@ftfl.ca
# $FreeBSD$

PORTNAME=		diamond
PORTVERSION=		0.8.6
DISTVERSIONPREFIX=	v
CATEGORIES=		biology

MAINTAINER=		jrm@ftfl.ca
COMMENT=		BLAST-compatible local sequence aligner

LICENSE=		BSD2CLAUSE

ONLY_FOR_ARCHS=		amd64

USES=			cmake:outsource compiler:c++11-lang

CFLAGS+=		-DNDEBUG

USE_GITHUB=		yes
GH_ACCOUNT=		bbuchfink

PLIST_FILES=		bin/diamond

.if ! defined(PACKAGE_BUILDING)
CXXFLAGS+=-march=native
.endif

.include <bsd.port.mk>
