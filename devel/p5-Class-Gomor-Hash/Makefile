# New ports collection makefile for:	Class-Gomor-Hash
# Date created:				01 Feb 2005
# Whom:					GomoR <netpkt@gomor.org>
#
# $FreeBSD$
#

PORTNAME=		Class-Gomor-Hash
PORTVERSION=		0.20
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN} \
			http://www.gomor.org/netpkt/
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=		p5-

MAINTAINER=		netpkt@gomor.org
COMMENT=		Class and object builder, hash version

PERL_CONFIGURE=	yes

MAN3=	Class::Gomor::Hash.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"Needs perl 5.6.0 or higher, install lang/perl5.6 and try again"
.endif

.include <bsd.port.post.mk>
