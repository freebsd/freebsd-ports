# New ports collection makefile for:	Data::TreeDumper
# Date created:				1 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Data-TreeDumper
PORTVERSION=	0.40
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Dumps a data structure in a tree fashion

BUILD_DEPENDS=	p5-Term-Size>=0:${PORTSDIR}/devel/p5-Term-Size \
		p5-Text-Tabs+Wrap>=0:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap \
		p5-Check-ISA>=0:${PORTSDIR}/devel/p5-Check-ISA \
		p5-Devel-Size>=0:${PORTSDIR}/devel/p5-Devel-Size \
		p5-Sort-Naturally>=0:${PORTSDIR}/textproc/p5-Sort-Naturally
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=		Data::TreeDumper.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
