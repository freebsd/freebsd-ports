# $FreeBSD$

PORTNAME=	pixz
PORTVERSION=	1.0.6
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Parallel, indexing version of XZ

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asciidoc:textproc/asciidoc

USES=		autoreconf libarchive pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	vasi

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/${PORTNAME} man/man1/pixz.1.gz

.include <bsd.port.mk>
