# New ports collection makefile for:	devel/p5-Sub-Exporter-ForMethods
# Date created:				May 27, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sub-Exporter-ForMethods
PORTVERSION=	0.100050
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Helper routines for using Sub::Exporter to build methods

RUN_DEPENDS=	p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Sub-Exporter>=0.978:${PORTSDIR}/devel/p5-Sub-Exporter
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Sub::Exporter::ForMethods.3

.include <bsd.port.mk>
