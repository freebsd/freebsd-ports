# New ports collection makefile for:	POE-Component-LaDBI
# Date created:	   09 February 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-LaDBI
PORTVERSION=	1.2.1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl extension for asynchronous non-blocking DBI calls in POE

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::LaDBI.3 POE::Component::LaDBI::Commands.3 \
		POE::Component::LaDBI::Engine.3 \
		POE::Component::LaDBI::Request.3 \
		POE::Component::LaDBI::Response.3

.include <bsd.port.pre.mk>

post-extract:
	${RM} ${WRKSRC}/*.pl

post-patch:
	@${PERL} -pi -e 's!(?=read_answer_yes\()!0 and !;' ${WRKSRC}/Makefile.PL

.if ${PERL_LEVEL} < 500600
IGNORE=	Perl 5.6 or newer required. Install lang/perl5.8 or lang/perl5 and try again.
.endif

.include <bsd.port.post.mk>
