PORTNAME=		minimap2
DISTVERSIONPREFIX=	v
DISTVERSION=		2.24
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Pairwise aligner for genomic and spliced nucleotide sequences

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	simde>0:devel/simde

USES=		gmake localbase
USE_GITHUB=	yes

GH_ACCOUNT=	lh3

ALL_TARGET=	extra
INSTALL_TARGET=	install-strip

MAKEFILE=	Makefile.simde

.include <bsd.port.mk>
