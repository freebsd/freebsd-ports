# New ports collection makefile for:	p5-Smart-Comments
# Date created:				24 May 2005
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Smart-Comments
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CH/CHORNY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Comments that do more than just sit there

PERL_MODBUILD=	yes

MAN3=		Smart::Comments.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500900
RUN_DEPENDS+=	p5-version>=0:${PORTSDIR}/devel/p5-version
.endif

.if ${PERL_LEVEL} < 500905
RUN_DEPENDS+=	p5-Text-Balanced>=2:${PORTSDIR}/textproc/p5-Text-Balanced
.endif

.include <bsd.port.post.mk>
