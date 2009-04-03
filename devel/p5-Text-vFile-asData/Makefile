# New ports collection makefile for:	Text::vFile::asData
# Date created:		21 Apr 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-vFile-asData
PORTVERSION=	0.05
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Parse vFile formatted files into data structures

RUN_DEPENDS=	p5-Class-Accessor-Chained>0:${PORTSDIR}/devel/p5-Class-Accessor-Chained
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		holidays_ical.1 rota_ical.cgi.1
MAN3=		Text::vFile::asData.3

.include <bsd.port.mk>
