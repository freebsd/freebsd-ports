# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	transdecoder
PORTVERSION=	2.1.0
DISTVERSIONPREFIX=v
CATEGORIES=	biology perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Identify candidate coding regions within transcript sequences

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	cd-hit>=4.6.1:biology/cd-hit \
		p5-URI>0:net/p5-URI

NO_BUILD=	yes
NO_ARCH=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	sample_data/cufflinks_example/runMe.sh \
		sample_data/pasa_example/runMe.sh \
		sample_data/simple_transcriptome_target/runMe.sh \
		util/pfam_mpi.pbs

USE_GITHUB=	yes
GH_PROJECT=	TransDecoder

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${PORTVERSION}

PERL_MOD_DIR=	${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
PERL_UTIL_DIR=	${PREFIX}/libexec/${PORTNAME}

post-patch:
	${REINPLACE_CMD} \
		-e 's|$$FindBin::RealBin/PerlLib|${PERL_MOD_DIR}|g' \
		-e 's|$$FindBin::Bin/../PerlLib|${PERL_MOD_DIR}|g' \
		-e 's|$$FindBin::RealBin/util|${PERL_UTIL_DIR}|g' \
		${WRKSRC}/TransDecoder* ${WRKSRC}/util/*.pl

do-install:
	${MKDIR} ${STAGEDIR}${PERL_MOD_DIR} ${STAGEDIR}${PERL_UTIL_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/PerlLib/* ${STAGEDIR}${PERL_MOD_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/TransDecoder* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/util/*.pl ${STAGEDIR}${PERL_UTIL_DIR}

.include <bsd.port.mk>
