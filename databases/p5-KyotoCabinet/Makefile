# Created by: Geraud CONTINSOUZAS <geraud@gcu.info>
# $FreeBSD$

PORTNAME=	KyotoCabinet
PORTVERSION=	1.20
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	https://dbmx.net/kyotocabinet/perlpkg/
PKGNAMEPREFIX=	p5-
DISTNAME=	kyotocabinet-perl-${PORTVERSION}

MAINTAINER=	geraud@gcu.info
COMMENT=	Perl extension for KyotoCabinet

LICENSE=	GPLv3

LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	*.pl

post-patch:
# do not run misc tests which seem to be endless
	@${REINPLACE_CMD} -e '/kctest.pl misc/d' ${WRKSRC}/test.pl

.include <bsd.port.mk>
