# $FreeBSD$

PORTNAME=	TrimGalore
DISTVERSION=	0.4.5
CATEGORIES=	biology perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Wrapper around Cutadapt and FastQC for adapter and quality trimming

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cutadapt>0:biology/py-cutadapt@${PY_FLAVOR} \
		fastqc>0:biology/fastqc

NO_ARCH=	yes
NO_BUILD=	yes

USES=		perl5 python:env shebangfix
SHEBANG_FILES=	trim_galore
USE_PERL5=	run

USE_GITHUB=	yes
GH_ACCOUNT=	FelixKrueger

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/trim_galore ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} test_files ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
