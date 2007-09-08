# New ports collection makefile for:	p5-Data-Pageset
# Date created:				29 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Pageset
PORTVERSION=	1.03
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Page numbering and page sets

BUILD_DEPENDS=	${SITE_PERL}/Data/Page.pm:${PORTSDIR}/databases/p5-Data-Page
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Data::Pageset.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
