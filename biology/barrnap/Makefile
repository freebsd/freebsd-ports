PORTNAME=	barrnap
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.6
CATEGORIES=	biology science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	BAsic Rapid Ribosomal RNA Predictor
WWW=		https://github.com/tseemann/barrnap

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bedtools:biology/bedtools \
		cmsearch:biology/infernal \
		p5-File-Which>0:sysutils/p5-File-Which \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-Path-Tiny>0:devel/p5-Path-Tiny \
		seqkit:biology/seqkit
TEST_DEPENDS=	bats:devel/bats-core

USES=		gmake perl5 shebangfix
SHEBANG_FILES=	bin/barrnap test/test.sh

USE_GITHUB=	yes
GH_ACCOUNT=	tseemann

MAKE_ENV=	PREFIX=${PREFIX} DATADIR=${DATADIR}

INSTALL_TARGET=	install
TEST_TARGET=	test

NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|^my $$DEFAULT_DBDIR = .*|my $$DEFAULT_DBDIR = path("${DATADIR}/db");|' \
		${WRKSRC}/bin/barrnap

# tests as of 1.10.6: 17 tests, 0 failures, 7 skipped in 0 seconds

.include <bsd.port.mk>
