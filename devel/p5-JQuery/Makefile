PORTNAME=	JQuery
PORTVERSION=	1.06
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PETERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Interface to Jquery, a language based on JavaScript

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CGI-Application>=0:www/p5-CGI-Application \
		p5-CSS>=0:textproc/p5-CSS \
		p5-HTML-Table>=0:www/p5-HTML-Table \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-XML-Writer>=0:textproc/p5-XML-Writer

USES=		perl5 shebangfix
USE_PERL5=	modbuild

NO_ARCH=	yes

SHEBANG_FILES=	lib/JQuery/cgi-bin/*.pl

.include <bsd.port.mk>
