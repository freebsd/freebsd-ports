# New ports collection makefile for:	Class::Delegation
# Date created:		5 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Delegation
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Object-oriented delegation

PERL_CONFIGURE=	yes

MAN3=		Class::Delegation.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/demo/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
