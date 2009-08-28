# New ports collection makefile for:	Baseball-Sabermetrics
# Date created:				2006/07/21
# Whom:					chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Baseball-Sabermetrics
PORTVERSION=	0.03
CATEGORIES=	games perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Baseball Statistics Module

BUILD_DEPENDS=	p5-Data-Serializer>=0.29:${PORTSDIR}/devel/p5-Data-Serializer \
		p5-HTML-TableExtract>=2.08:${PORTSDIR}/www/p5-HTML-TableExtract \
		p5-libwww>=5.801:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Baseball::Sabermetrics.3

.include <bsd.port.mk>
