# New ports collection makefile for:	p5-Config-INI-Simple
# Date created:		2006-07-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Config-INI-Simple
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Config
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Simple reading and writing from an INI file

PERL_CONFIGURE=	yes
USE_ZIP=	yes

MAN3=		Config::INI::Simple.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500807
IGNORE=		requires perl 5.8.7 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
