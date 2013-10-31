# Created by: Ruben van Staveren
# $FreeBSD$

PORTNAME=	Thread-Cancel
PORTVERSION=	1.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cancel (i.e., kill) threads

RUN_DEPENDS=	p5-threads>=1.34:${PORTSDIR}/devel/p5-threads
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

pre-everything::
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "This module requires a threaded perl.  If your install"
	@${ECHO_MSG} "is not threaded please install lang/${PERL_PORT} with threads"
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.mk>
