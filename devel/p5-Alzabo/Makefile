# Created by: mat
# $FreeBSD$

PORTNAME=	Alzabo
PORTVERSION=	0.92
PORTREVISION=	1
CATEGORIES=	devel databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Data modelling tool and RDBMS-OO mapper

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-Class-Factory-Util>=0:devel/p5-Class-Factory-Util \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash \
		p5-DBI>=0:databases/p5-DBI

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

EXAMPLES=	eg/alzabo_grep eg/alzabo_to_ascii eg/convert.pl eg/reverse_cardinality.pl
EXAMPLESMASON=	mason/widgets/edit_field_checkbox mason/widgets/edit_field_text_input mason/widgets/edit_field_textarea mason/widgets/fk_to_one_select mason/widgets/insert mason/widgets/insert_or_update mason/widgets/update
PORTDOCS=	README Changes TODO
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/mason
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLESMASON:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}/mason

.include <bsd.port.mk>
