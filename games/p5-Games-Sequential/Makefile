# New ports collection makefile for:	p5-Games-Sequential
# Date created: 			27 July 2005
# Whom: 				Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Games-Sequential
PORTVERSION=	0.4.3
CATEGORIES=	games perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Games
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@daltons.ca
COMMENT=	Sequential games framework with OO interface

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	 yes

MAN3=		Games::Sequential.3 Games::Sequential::Position.3

.include <bsd.port.pre.mk>

.if (${PERL_LEVEL} < 500601)
BROKEN=	"Perl 5.6.1 or above is required"
.endif

.include <bsd.port.post.mk>
