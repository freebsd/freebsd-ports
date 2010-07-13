# New ports collection makefile for:	devel/MooseX-SimpleConfig
# Date created:				25 February 2009
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-SimpleConfig
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A Moose role for setting attributes from a simple configfile

RUN_DEPENDS=	p5-Moose>=0.35:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-ConfigFromFile>=0.02:${PORTSDIR}/devel/p5-MooseX-ConfigFromFile \
		p5-Config-Any>=0.13:${PORTSDIR}/devel/p5-Config-Any
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::SimpleConfig.3

post-patch:
	@${PERL} -pi -e '$$_="" if m/Test::More|auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
