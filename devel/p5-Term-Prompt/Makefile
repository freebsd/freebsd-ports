# New ports collection makefile for:	devel/p5-Term-Prompt
# Date created:				25 April 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Term-Prompt
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Term::Prompt.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
