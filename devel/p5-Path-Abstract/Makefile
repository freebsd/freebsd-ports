# New ports collection makefile for:	p5-Path-Abstract
# Date created:		2011-04-26
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Path-Abstract
PORTVERSION=	0.096
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ROKR
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Fast and featureful UNIX-style path parsing and manipulation

BUILD_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN3=	Path::Abstract.3 Path::Abstract::Underload.3

.include <bsd.port.mk>
