PORTNAME=		pooler
DISTVERSIONPREFIX=	v
DISTVERSION=		1.78
PORTREVISION=		1
CATEGORIES=		biology

MAINTAINER=	ssb22@cam.ac.uk
COMMENT=	Optimise DNA sequencing primer-set combinations

LICENSE=	APACHE20
LICENSE_FILE=	${WRKDIR}/${GH_PROJECT}-${PORTVERSION}/LICENSE

USE_GITHUB=	yes

GH_ACCOUNT=	ssb22
GH_PROJECT=	PrimerPooler

WRKSRC_SUBDIR=	pooler
CFLAGS+=	-fopenmp

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/pooler man/man1/pooler.1.gz share/applications/pooler.desktop

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USES+=		compiler:gcc-c++11-lib
.endif

.include <bsd.port.mk>
