# Created by: Carlos J. Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	LaTeXML
PORTVERSION=	0.8.2
CATEGORIES=	converters perl5
MASTER_SITES=	http://dlmf.nist.gov/LaTeXML/releases/
PKGNAMEPREFIX=	p5-

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	LaTeX to XML/HTML/MathML converter in Perl

LICENSE=	PD CC0-1.0
LICENSE_COMB=	dual
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git:devel/git \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-Image-Size>=0:graphics/p5-Image-Size \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-XML-LibXML>=1.62:textproc/p5-XML-LibXML \
		p5-XML-LibXSLT>=1.58:textproc/p5-XML-LibXSLT \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent \
		p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-libwww>=0:www/p5-libwww \
		p5-Test-More-UTF8>=0:devel/p5-Test-More-UTF8 \
		p5-Text-Unidecode>=0:converters/p5-Text-Unidecode \
		p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	configure
USE_TEX=	kpathsea
NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=		Changes README.pod manual.pdf

OPTIONS_DEFINE=	DOCS

post-install:
	${FIND} ${STAGEDIR}/${PREFIX} -name .packlist | \
		${XARGS} ${REINPLACE_CMD} -e 's|^${STAGEDIR}||'
	${RM} ${STAGEDIR}${PREFIX}/share/texmf-local/tex/latex/latexml/.packlist.bak

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
