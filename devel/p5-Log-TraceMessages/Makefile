# New ports collection makefile for:	Log::TraceMessages
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Log-TraceMessages
PORTVERSION=	1.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/E/ED/EDAVIS
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca
COMMENT=	Perl extension for trace messages used in debugging

BUILD_DEPENDS=	${SITE_PERL}/HTML/FromText.pm:${PORTSDIR}/www/p5-HTML-FromText
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Log::TraceMessages.3

.include <bsd.port.mk>
