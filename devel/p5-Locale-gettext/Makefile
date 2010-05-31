# New ports collection makefile for:	p5-gettext
# Date created:			1 February 2000
# Whom:				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	1.05
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=Locale
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Message handling functions

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
USE_GETTEXT=	yes

MAN3=		Locale::gettext.3

.include <bsd.port.mk>
