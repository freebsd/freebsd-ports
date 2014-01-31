# $FreeBSD$

PORTNAME=	TokyoCabinet
PORTVERSION=	1.34
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://fallabs.com/tokyocabinet/perlpkg/
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMEPREFIX=	p5-
DISTNAME=	tokyocabinet-perl-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for TokyoCabinet

LIB_DEPENDS=	libtokyocabinet.so:${PORTSDIR}/databases/tokyocabinet

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
