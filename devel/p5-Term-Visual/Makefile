# New ports collection makefile for:	Term-Visual
# Date created:				2007/03/21
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Term-Visual
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Split-terminal user interface

BUILD_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-Curses>=0:${PORTSDIR}/devel/p5-Curses
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Term::Visual.3

.include <bsd.port.mk>
