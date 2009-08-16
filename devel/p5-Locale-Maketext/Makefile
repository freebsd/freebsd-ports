# New ports collection makefile for:	p5-Locale-Maketext
# Date created:			March 13, 2000
# Whom:				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	Locale-Maketext
PORTVERSION=	1.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A framework for software localization and inheritance-based lexicons

PERL_CONFIGURE=	YES

MAN3=		Locale::Maketext.3 Locale::Maketext::TPJ13.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
RUN_DEPENDS+=	p5-I18N-LangTags>=0.30:${PORTSDIR}/misc/p5-I18N-LangTags
.endif

.include <bsd.port.post.mk>
