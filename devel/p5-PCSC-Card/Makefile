# New ports collection makefile for:	p5-PCSC-Card
# Date created:		12 September 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	PCSC-Card
PORTVERSION=	1.2.2
CATEGORIES=	devel perl5
MASTER_SITES=	http://ludovic.rousseau.free.fr/softwares/pcsc-perl/
PKGNAMEPREFIX=	p5-
DISTNAME=	pcsc-perl-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Perl bindings for the PC/SC Lite Framework

LIB_DEPENDS=	pcsclite.0:${PORTSDIR}/devel/pcsc-lite

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLDIRS=site
MAKE_ENV=	"LOCALBASE=$(LOCALBASE)"

MAN3=		Chipcard::PCSC::Card.3 Chipcard::PCSC.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
