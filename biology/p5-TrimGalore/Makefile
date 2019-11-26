# $FreeBSD$

PORTNAME=	TrimGalore
DISTVERSION=	0.6.5
CATEGORIES=	biology perl5 python
PKGNAMEPREFIX=	p5-

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Wrapper around Cutadapt and FastQC for adapter and quality trimming

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cutadapt>=2.5:biology/py-cutadapt@${PY_FLAVOR} \
		fastqc>0:biology/fastqc

# Future: Can 3.4+ be determined from cutadapt dep?
USES=		perl5 python:env,3.4+ shebangfix
USE_PERL5=	run
USE_GITHUB=	yes

SHEBANG_FILES=	trim_galore
GH_ACCOUNT=	FelixKrueger

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	trim_galore-test

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/trim_galore ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/trim_galore-test ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} test_files ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
