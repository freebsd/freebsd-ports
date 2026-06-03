PORTNAME=	gffread
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.9
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	GFF/GTF format conversions, filtering, FASTA extraction, etc
WWW=		https://ccb.jhu.edu/software/stringtie/gff.shtml#gffread

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes

GH_ACCOUNT=	gpertea
GH_TUPLE=	gpertea:gclib:v0.12.8:gpertea/gclib

INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	cufflinks

PLIST_FILES=	bin/gffread

.include <bsd.port.mk>
