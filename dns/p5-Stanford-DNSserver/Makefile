# New ports collection makefile for:	p5-Stanford-DNSserver
# Date created:				5 November 2004
# Whom:	      				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Stanford-DNSserver
PORTVERSION=	1.2.0
CATEGORIES=	dns perl5
MASTER_SITES=	http://www.stanford.edu/~riepel/lbnamed/Stanford-DNSserver/
PKGNAMEPREFIX=	p5-

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A DNS name server framework with a Perl backend

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Stanford::DNS.3 Stanford::DNSserver.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		does not work with the IO::Socket::INET module in Perl 5.00503
.endif

.include <bsd.port.post.mk>
