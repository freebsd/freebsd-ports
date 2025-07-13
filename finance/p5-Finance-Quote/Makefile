PORTNAME=	Finance-Quote
PORTVERSION=	1.66
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Get stock and mutual fund quotes from various exchanges
WWW=		https://metacpan.org/release/Finance-Quote

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-Devel-Trace>=0.12:devel/p5-Devel-Trace \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-TableExtract>=0:www/p5-HTML-TableExtract \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-HTML-TreeBuilder-XPath>=0:www/p5-HTML-TreeBuilder-XPath \
		p5-HTTP-CookieJar>=0.014:www/p5-HTTP-CookieJar \
		p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-JSON>=0:converters/p5-JSON \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Mozilla-CA>=0:www/p5-Mozilla-CA \
		p5-Net-SSLeay>=1.92:security/p5-Net-SSLeay \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-Smart-Comments>=1.000005:devel/p5-Smart-Comments \
		p5-Spreadsheet-XLSX>=0:textproc/p5-Spreadsheet-XLSX \
		p5-String-Util>=0:textproc/p5-String-Util \
		p5-Text-Template>=0:textproc/p5-Text-Template \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-URI>=3.31:net/p5-URI \
		p5-Web-Scraper>=0:www/p5-Web-Scraper \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-libwww>=6.48:www/p5-libwww
TEST_DEPENDS=	p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Date-Range>=0:devel/p5-Date-Range \
		p5-Date-Simple>=0:devel/p5-Date-Simple \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-ISO8601>=0:devel/p5-DateTime-Format-ISO8601 \
		p5-Module-CPANTS-Analyse>=0:devel/p5-Module-CPANTS-Analyse \
		p5-Test-Kwalitee>=0:devel/p5-Test-Kwalitee \
		p5-Test-Perl-Critic>=0:textproc/p5-Test-Perl-Critic

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
