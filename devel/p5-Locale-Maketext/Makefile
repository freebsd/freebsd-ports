# New ports collection makefile for:	p5-Locale-Maketext
# Date created:			March 13, 2000
# Whom:				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	Locale-Maketext
PORTVERSION=	1.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Locale
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A framework for software localization and inheritance-based lexicons

BUILD_DEPENDS=	${SITE_PERL}/I18N/LangTags.pm:${PORTSDIR}/misc/p5-I18N-LangTags
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Locale::Maketext.3 Locale::Maketext::TPJ13.3

.include <bsd.port.mk>
