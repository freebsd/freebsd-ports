# New ports collection makefile for:	POE-API-Peek
# Date created:	   11 November 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-API-Peek
PORTVERSION=	1.23
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Peek into the internals of a running POE environment

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		POE::API::Peek.3

post-patch:
	${RM} ${WRKSRC}/inc/Module/Install/AutoInstall.pm
	${PERL} -pi -e 's/^auto_install.*//;' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	"Perl 5.6.1 or newer required. Install lang/perl5 or lang/perl5.8 and try again."
.endif

.include <bsd.port.post.mk>
