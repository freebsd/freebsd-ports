# New ports collection makefile for:	p5-AutoLoader
# Date created:				Jan 18 2007
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AutoLoader
PORTVERSION=	5.63
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Load subroutines only on demand

PERL_CONFIGURE=	yes

MAN3=		AutoLoader.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		this program only support perl 5.6.1 or above
.endif

.include <bsd.port.post.mk>
