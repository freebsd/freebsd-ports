# New ports collection makefile for:	Class::Delegation
# Date created:		5 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Delegation
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Class::Delegation.3

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/demo/* \
		${PREFIX}/share/examples/${PORTNAME}
.endif

.include <bsd.port.mk>
