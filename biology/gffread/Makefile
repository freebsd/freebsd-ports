PORTNAME=	gffread
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.7
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	GFF/GTF format conversions, filtering, FASTA extraction, etc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes

GH_ACCOUNT=	gpertea
GH_TUPLE=	gpertea:gclib:v${DISTVERSION}:gpertea/gclib

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/gffread

.include <bsd.port.mk>
