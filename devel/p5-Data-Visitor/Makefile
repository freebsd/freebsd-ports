# New ports collection makefile for:	Data-Visitor
# Date created:		26 Mar 2006
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Visitor
PORTVERSION=	0.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Visitor style traversal of Perl data structures

RUN_DEPENDS=	p5-Mouse>=0.04:${PORTSDIR}/devel/p5-Mouse \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean \
		p5-Tie-ToObject>=0.01:${PORTSDIR}/devel/p5-Tie-ToObject \
		p5-Data-Alias>=0:${PORTSDIR}/devel/p5-Data-Alias \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Data::Visitor.3 \
	Data::Visitor::Callback.3

post-extract:
	@${REINPLACE_CMD} -e '/Test::/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
