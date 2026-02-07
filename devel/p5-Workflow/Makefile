PORTNAME=	Workflow
DISTVERSION=	2.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Simple, flexible system to implement workflows
WWW=		https://metacpan.org/release/Workflow

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0.18:devel/p5-Class-Accessor \
		p5-Class-Factory>=1:devel/p5-Class-Factory \
		p5-Data-UUID>=0:devel/p5-Data-UUID \
		p5-DateTime-Format-Strptime>=1:devel/p5-DateTime-Format-Strptime \
		p5-DateTime>=0.15:devel/p5-DateTime \
		p5-DBI>=0:databases/p5-DBI \
		p5-Exception-Class>=1.10:devel/p5-Exception-Class \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Log-Any>=1.050:devel/p5-Log-Any \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-Syntax-Keyword-Try>=0.25:devel/p5-Syntax-Keyword-Try \
		p5-XML-Simple>=2.00:textproc/p5-XML-Simple \
		p5-YAML>=1.30:textproc/p5-YAML
TEST_DEPENDS=	p5-DBD-Mock>=1.59:databases/p5-DBD-Mock \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Mock-MonkeyPatch>=1.02:devel/p5-Mock-MonkeyPatch \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Without-Module>=0.20:devel/p5-Test-Without-Module

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=		EXAMPLES LINKS
LINKS_DESC=		Test if pod web links are reachable during "make test"
LINKS_TEST_DEPENDS=	p5-Test-Pod-Links>=0:devel/p5-Test-Pod-Links

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLINKS}
TEST_ENV+=	POD_LINKS=yes
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} struct/\* ${STAGEDIR}${DATADIR}/)
	@${ECHO_MSG} "===> SQL data structures installed in ${DATADIR}."

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/eg && ${COPYTREE_SHARE} ticket/\* ${STAGEDIR}${EXAMPLESDIR}/)
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."

.include <bsd.port.mk>
