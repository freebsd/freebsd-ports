PORTNAME=	SVN-Web
PORTVERSION=	0.63
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Subversion repository web frontend

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Cache-Cache>=0:devel/p5-Cache-Cache \
		p5-Exception-Class>=1.22:devel/p5-Exception-Class \
		p5-HTTP-Server-Simple>=0:www/p5-HTTP-Server-Simple \
		p5-Locale-Maketext-Lexicon>=0:devel/p5-Locale-Maketext-Lexicon \
		p5-Plack>=0:www/p5-Plack \
		p5-Template-Plugin-Clickable-Email>=0:www/p5-Template-Plugin-Clickable-Email \
		p5-Template-Plugin-Clickable>=0:www/p5-Template-Plugin-Clickable \
		p5-Template-Plugin-Number-Format>=0:www/p5-Template-Plugin-Number-Format \
		p5-Template-Plugin-Subst>=0:www/p5-Template-Plugin-Subst \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Text-Diff-HTML>=0:textproc/p5-Text-Diff-HTML \
		p5-Text-Diff>=0:textproc/p5-Text-Diff \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-URI>=0:net/p5-URI \
		p5-XML-RSS-Parser>=0:textproc/p5-XML-RSS-Parser \
		p5-XML-RSS>=0:textproc/p5-XML-RSS \
		p5-YAML>=0:textproc/p5-YAML \
		p5-subversion>=0:devel/p5-subversion
TEST_DEPENDS=	p5-Test-Benchmark>=0:devel/p5-Test-Benchmark \
		p5-Test-HTML-Tidy>=0:devel/p5-Test-HTML-Tidy \
		p5-Test-WWW-Mechanize>=0:devel/p5-Test-WWW-Mechanize

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/svnweb-install
USE_PERL5=	configure
CONFIGURE_ARGS=	--skip_questions

post-install:
	@${MKDIR} -p ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKSRC}/SVN-Web.psgi ${WRKSRC}/template ${WRKSRC}/css ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/svnweb-install ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
