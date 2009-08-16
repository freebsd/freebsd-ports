# New ports collection makefile for:	UNIVERSAL-exports
# Date created:		16 April 2003
# Whom:			Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	UNIVERSAL-exports
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lightweight, universal exporting of variables

BUILD_DEPENDS=	${SITE_PERL}/Exporter/Lite.pm:${PORTSDIR}/devel/p5-Exporter-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		UNIVERSAL::exports.3

.include <bsd.port.mk>
