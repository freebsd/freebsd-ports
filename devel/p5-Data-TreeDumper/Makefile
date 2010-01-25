# New ports collection makefile for:	Data::TreeDumper
# Date created:				1 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Data-TreeDumper
PORTVERSION=	0.37
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Dumps a data structure in a tree fashion

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/Size.pm:${PORTSDIR}/devel/p5-Term-Size \
		${SITE_PERL}/Text/Wrap.pm:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap \
		${SITE_PERL}/Class/ISA.pm:${PORTSDIR}/devel/p5-Class-ISA \
		${SITE_PERL}/${PERL_ARCH}/Devel/Size.pm:${PORTSDIR}/devel/p5-Devel-Size \
		${SITE_PERL}/Sort/Naturally.pm:${PORTSDIR}/textproc/p5-Sort-Naturally
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Data::TreeDumper.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
