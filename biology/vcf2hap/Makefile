PORTNAME=	vcf2hap
DISTVERSION=	0.1.4
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generate .hap file from VCF for haplohseq

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbiolibc.so:biology/biolibc libxtend.so:devel/libxtend

USE_GITHUB=	yes
GH_ACCOUNT=	auerlab

MAKE_ENV=	VERSION=${PORTVERSION}
PLIST_FILES=	bin/vcf2hap man/man1/vcf2hap.1.gz

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

do-test:
	(cd ${WRKSRC}/Test && ./run-test.sh)

.include <bsd.port.mk>
