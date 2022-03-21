PORTNAME=	fastq-trim
DISTVERSION=	0.1.1-4
DISTVERSIONSUFFIX=	-g7e3c5ff
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightening fast sequence read trimmer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:biology/biolibc libxtend.so:devel/libxtend

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ENV=	VERSION=${PORTVERSION}

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
