# New ports collection makefile for:	devel/p5-Acme-Comment
# Date created:				2012-07-18
# Whom:					Marcello Coutinho <marcellocoutinho@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Acme-Comment
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	marcellocoutinho@gmail.com
COMMENT=	Allow multi-line comments which are filtered out

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

MAN3=		Acme::Comment.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Text-Balanced>=1.99:${PORTSDIR}/textproc/p5-Text-Balanced
RUN_DEPENDS+=	p5-Text-Balanced>=1.99:${PORTSDIR}/textproc/p5-Text-Balanced
.endif

.include <bsd.port.post.mk>
