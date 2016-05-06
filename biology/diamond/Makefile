# Created by: jrm@ftfl.ca
# $FreeBSD$

PORTNAME=		diamond
PORTVERSION=		0.7.12
DISTVERSIONPREFIX=	v
CATEGORIES=		biology

MAINTAINER=		jrm@ftfl.ca
COMMENT=		BLAST-compatible local sequence aligner

LICENSE=		BSD2CLAUSE

BUILD_DEPENDS=		${LOCALBASE}/include/boost:devel/boost-libs
RUN_DEPENDS=		${LOCALBASE}/include/boost:devel/boost-libs

ONLY_FOR_ARCHS=		amd64

USES=			cmake:outsource

CFLAGS+=		-DNDEBUG

USE_GITHUB=		yes
GH_ACCOUNT=		bbuchfink

PLIST_FILES=		bin/diamond

.include <bsd.port.mk>
