# New ports collection makefile for:	p5-Locale-Maketext
# Date created:			March 13, 2000
# Whom:				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	Locale-Maketext
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Locale
PKGNAMEPREFIX=	p5-

MAINTAINER=	mns@shepard.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/I18N/LangTags.pm:${PORTSDIR}/misc/p5-I18N-LangTags
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Locale::Maketext.3 Locale::Maketext::TPJ13.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
