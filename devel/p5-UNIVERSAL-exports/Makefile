# New ports collection makefile for:	UNIVERSAL-exports
# Date created:		16 April 2003
# Whom:			Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	UNIVERSAL-exports
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	UNIVERSAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Lightweight, universal exporting of variables

BUILD_DEPENDS=	${SITE_PERL}/Exporter/Lite.pm:${PORTSDIR}/devel/p5-Exporter-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		UNIVERSAL::exports.3 UNIVERSAL::require.3

.include <bsd.port.mk>
