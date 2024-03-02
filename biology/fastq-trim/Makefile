PORTNAME=	fastq-trim
DISTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightening fast sequence read trimmer
WWW=		https://github.com/outpaddling/Fastq-trim

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:biology/biolibc libxtend.so:devel/libxtend

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

MAKE_ENV=	VERSION=${PORTVERSION} MANPREFIX=${PREFIX}/share

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
