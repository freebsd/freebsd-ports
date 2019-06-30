# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Finance-Quote
PORTVERSION=	1.48
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Get stock and mutual fund quotes from various exchanges

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CGI>=0:www/p5-CGI \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-TableExtract>=0:www/p5-HTML-TableExtract \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-JSON>=0:converters/p5-JSON \
		p5-JSON-Parse>=0:devel/p5-JSON-Parse \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Mozilla-CA>=0:www/p5-Mozilla-CA \
		p5-String-Util>=0:textproc/p5-String-Util \
		p5-Text-Template>=0:textproc/p5-Text-Template \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-Test-Kwalitee>=0:devel/p5-Test-Kwalitee \
		p5-Test-Perl-Critic>=0:textproc/p5-Test-Perl-Critic

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
