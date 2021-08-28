PORTNAME=		pooler
DISTVERSIONPREFIX=	v
DISTVERSION=		1.78
CATEGORIES=		biology

MAINTAINER=	ssb22@cam.ac.uk
COMMENT=	Optimise DNA sequencing primer-set combinations

LICENSE=	APACHE20
LICENSE_FILE=	${WRKDIR}/${GH_PROJECT}-${PORTVERSION}/LICENSE

# Not needed on x86, aarch64, or ppc64-13.x
# Might need gcc on 32-bit ARM/PPC
USES=		compiler:openmp
USE_GITHUB=	yes

GH_ACCOUNT=	ssb22
GH_PROJECT=	PrimerPooler

WRKSRC_SUBDIR=	pooler
CFLAGS+=	-fopenmp

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/pooler man/man1/pooler.1.gz share/applications/pooler.desktop

.include <bsd.port.mk>
