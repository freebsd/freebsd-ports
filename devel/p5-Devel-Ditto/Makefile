# New ports collection makefile for:	devel/p5-Devel-Ditto
# Date created:				02 July 2009
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-Ditto
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Devel::Ditto - Identify where print output comes from

RUN_DEPENDS=	p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Devel::Ditto.3 Devel::Ditto::Color.3 Devel::Ditto::Colour.3

.include <bsd.port.mk>
