# Created by: jrm@ftfl.ca
# $FreeBSD$

PORTNAME=		diamond
PORTVERSION=		0.7.12
DISTVERSIONPREFIX=	v
PORTREVISION=		1
CATEGORIES=		biology

MAINTAINER=		jrm@ftfl.ca
COMMENT=		BLAST-compatible local sequence aligner

LICENSE=		BSD2CLAUSE

LIB_DEPENDS=		libboost_system.so:devel/boost-libs

ONLY_FOR_ARCHS=		amd64

USES=			cmake:outsource

CFLAGS+=		-DNDEBUG

USE_GITHUB=		yes
GH_ACCOUNT=		bbuchfink

PLIST_FILES=		bin/diamond

.include <bsd.port.mk>
