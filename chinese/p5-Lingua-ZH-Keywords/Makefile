# ex:ts=8
# Ports collection makefile for:	p5-Lingua-ZH-Keywords
# Date Created:			Oct 10, 2003
# Whom:				clsung
#
# $FreeBSD$

PORTNAME=	Lingua-ZH-Keywords
PORTVERSION=	0.04
CATEGORIES=	chinese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese Keywords Extraction via Lingua::ZH::TaBE

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Lingua/ZH/TaBE.pm:${PORTSDIR}/chinese/p5-Lingua-ZH-TaBE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lingua::ZH::Keywords.3

.include <bsd.port.mk>
