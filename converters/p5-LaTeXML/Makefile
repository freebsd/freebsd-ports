# Created by: Carlos J. Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	LaTeXML
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	http://dlmf.nist.gov/LaTeXML/releases/
PKGNAMEPREFIX=	p5-

MAINTAINER=	cpm@fbsd.es
COMMENT=	LaTeX to XML/HTML/MathML converter in Perl

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/git:${PORTSDIR}/devel/git \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-XML-LibXML>=1.62:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-LibXSLT>=1.58:${PORTSDIR}/textproc/p5-XML-LibXSLT \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-Getopt-Long>=2.37:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Pod-Parser>=0:${PORTSDIR}/textproc/p5-Pod-Parser \
		p5-Test-More-UTF8>=0:${PORTSDIR}/devel/p5-Test-More-UTF8 \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

USES=		perl5
USE_PERL5=	configure
USE_TEX=	kpathsea
NO_BUILD=	yes

PORTDOCS=		Changes INSTALL MANIFEST README manual.pdf

OPTIONS_DEFINE=	DOCS

post-install:
	${FIND} ${STAGEDIR}/${PREFIX} -name .packlist | \
		${XARGS} ${REINPLACE_CMD} -e 's|^${STAGEDIR}||'
	${RM} ${STAGEDIR}${PREFIX}/share/texmf-local/tex/latex/latexml/.packlist.bak

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
