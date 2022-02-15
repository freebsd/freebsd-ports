# Created by: Sergei Vyshenski

PORTNAME=	Workflow
DISTVERSION=	1.59
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Simple, flexible system to implement workflows

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0.18:devel/p5-Class-Accessor \
		p5-Class-Factory>=1:devel/p5-Class-Factory \
		p5-Class-Observable>=1.04:devel/p5-Class-Observable \
		p5-Data-UUID>=0:devel/p5-Data-UUID \
		p5-DateTime-Format-Strptime>=1:devel/p5-DateTime-Format-Strptime \
		p5-DateTime>=0.15:devel/p5-DateTime \
		p5-DBI>=0:databases/p5-DBI \
		p5-Exception-Class>=1.10:devel/p5-Exception-Class \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Log-Log4perl>=0.34:devel/p5-Log-Log4perl \
		p5-XML-Simple>=2:textproc/p5-XML-Simple
TEST_DEPENDS=	p5-DBD-Mock>=0.10:databases/p5-DBD-Mock \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Mock-MonkeyPatch>=1.02:devel/p5-Mock-MonkeyPatch \
		p5-Perl-Critic>=1.38:textproc/p5-Perl-Critic \
		p5-Pod-Coverage-TrustPod>=0:devel/p5-Pod-Coverage-TrustPod \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Kwalitee>=1.21:devel/p5-Test-Kwalitee \
		p5-Test-Pod-Coverage>=1.08:devel/p5-Test-Pod-Coverage \
		p5-Test-Pod>=1.41:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} struct/\* ${STAGEDIR}${DATADIR}/)
	@${ECHO_MSG} "===> SQL data structures installed in ${DATADIR}."

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/eg && ${COPYTREE_SHARE} ticket/\* ${STAGEDIR}${EXAMPLESDIR}/)
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."

.include <bsd.port.mk>
