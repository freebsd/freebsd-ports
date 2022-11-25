PORTNAME=	barrnap
DISTVERSION=	0.9
CATEGORIES=	biology science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	BAsic Rapid Ribosomal RNA Predictor
WWW=		https://github.com/tseemann/barrnap

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bedtools:biology/bedtools \
		nhmmer:biology/hmmer

USES=		gmake perl5

USE_GITHUB=	yes
GH_ACCOUNT=	tseemann

NO_BUILD=	yes
NO_ARCH=	yes

TEST_TARGET=	test

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/barrnap ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} db ${STAGEDIR}${DATADIR}
	${REINPLACE_CMD} \
		-i '' -e 's|^my $$DBDIR = .*|my $$DBDIR = "${DATADIR}/db";|' \
		${STAGEDIR}${PREFIX}/bin/barrnap

.include <bsd.port.mk>
