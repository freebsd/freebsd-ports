# $FreeBSD$

PORTNAME=	diamond
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.24
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	BLAST-compatible local sequence aligner

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	bbuchfink

PLIST_FILES=	bin/diamond
.if defined(PACKAGE_BUILDING)
CFLAGS+=	-mtune=generic
.endif

.include <bsd.port.mk>
