PORTNAME=	TokyoCabinet
PORTVERSION=	1.34
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	LOCAL/kuriyama \
		https://dbmx.net/tokyocabinet/perlpkg/
PKGNAMEPREFIX=	p5-
DISTNAME=	tokyocabinet-perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for TokyoCabinet

LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
