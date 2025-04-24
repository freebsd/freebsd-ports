PORTNAME=	Thread-Cancel
PORTVERSION=	1.13
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cancel (i.e., kill) threads
WWW=		https://metacpan.org/release/Thread-Cancel

USES=		perl5
USE_PERL5=	configure

pre-everything::
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "This module requires a threaded perl.  If your install"
	@${ECHO_MSG} "is not threaded please install lang/${PERL_PORT} with threads"
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>
