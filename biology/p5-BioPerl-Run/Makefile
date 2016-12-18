# Created by: Mauricio Herrera Cuadra <mauricio@arareko.net>
# $FreeBSD$

PORTNAME=	BioPerl-Run
PORTVERSION=	1.6.901
PORTREVISION=	2
CATEGORIES=	biology perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Wrapper modules for common bioinformatics tools

LICENSE=	ART10 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff \
		p5-BioPerl>=1.6.0:biology/p5-BioPerl \
		p5-Config-Any>=0:devel/p5-Config-Any \
		p5-File-Sort>=0:misc/p5-File-Sort \
		p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-XML-Twig>=0:textproc/p5-XML-Twig
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	p5-bioperl-run-1.[13579]*

USE_GITHUB=	yes
GH_ACCOUNT=	bioperl
GH_PROJECT=	bioperl-run
GH_TAGNAME=	96ccd93

NO_ARCH=	yes
USES=		perl5 shebangfix
USE_PERL5=	modbuild
SHEBANG_FILES=	scripts/*

OPTIONS_DEFINE=	DOCS

post-build:
	(cd ${WRKSRC} && ${PERL} ./Build manifest)

post-install:
.for i in bioperl_application_installer multi_hmmsearch panalysis papplmaker run_neighbor run_protdist
	${CP} ${WRKSRC}/scripts/${i}.PLS ${STAGEDIR}${PREFIX}/bin/bp_${i}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS Changes INSTALL.PROGRAMS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
