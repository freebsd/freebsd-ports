# $FreeBSD$

PORTNAME=	diamond
PORTVERSION=	0.8.38
DISTVERSIONPREFIX=v
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	BLAST-compatible local sequence aligner

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/src/COPYING

ONLY_FOR_ARCHS=	amd64 i386

USES=		cmake:outsource

CFLAGS+=	-DNDEBUG

USE_GITHUB=	yes
GH_ACCOUNT=	bbuchfink

PLIST_FILES=	bin/diamond

.if ! defined(PACKAGE_BUILDING)
CXXFLAGS+=	-march=native
.endif

.include <bsd.port.mk>
