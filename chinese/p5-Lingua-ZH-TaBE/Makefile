# ex:ts=8
# Ports collection makefile for:	p5-Lingua-ZH-TaBE
# Date Created:			Jan 22, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Lingua-ZH-TaBE
PORTVERSION=	0.03
CATEGORIES=	chinese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/A/AU/AUTRIJUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tabe.2:${PORTSDIR}/chinese/libtabe

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Lingua::ZH::TaBE.3

.include <bsd.port.mk>
