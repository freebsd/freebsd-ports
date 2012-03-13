# New ports collection makefile for:	p5-Term-UI
# Date created:				31 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Term-UI
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Term::ReadLine UI made easy

PERL_CONFIGURE=	yes

MAN3=		Term::UI.3 Term::UI::History.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Log-Message-Simple>=0:${PORTSDIR}/devel/p5-Log-Message-Simple \
		p5-Params-Check>=0:${PORTSDIR}/devel/p5-Params-Check
RUN_DEPENDS+=	p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Log-Message-Simple>=0:${PORTSDIR}/devel/p5-Log-Message-Simple \
		p5-Params-Check>=0:${PORTSDIR}/devel/p5-Params-Check
.endif

.include <bsd.port.post.mk>
