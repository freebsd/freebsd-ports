# New ports collection makefile for:	Config::Fast
# Date created:				10 Feb 2004
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	Config-Fast
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Config
PKGNAMEPREFIX=	p5-

MAINTAINER=	kiwi@oav.net
COMMENT=	Extremely fast configuration file parser

PERL_CONFIGURE=	yes

MAN3=		Config::Fast.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Need at least perl 5.6 to build
.endif

.include <bsd.port.post.mk>
