# $FreeBSD$

PORTNAME=		pooler
DISTVERSIONPREFIX=	v
DISTVERSION=		1.75
CATEGORIES=		biology

MAINTAINER=	ssb22@cam.ac.uk
COMMENT=	Optimise DNA sequencing primer-set combinations

LICENSE=	APACHE20
LICENSE_FILE=	${WRKDIR}/${GH_PROJECT}-${PORTVERSION}/LICENSE

USES=		compiler:openmp
USE_GITHUB=	yes

GH_ACCOUNT=	ssb22
GH_PROJECT=	PrimerPooler

WRKSRC_SUBDIR=	pooler
CFLAGS+=	-fopenmp

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/pooler man/man1/pooler.1.gz

.include <bsd.port.mk>
