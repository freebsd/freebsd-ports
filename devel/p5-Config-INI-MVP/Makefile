# New ports collection makefile for:	Config-INI-MVP
# Date created:		27 December 2009
# Whom:			Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	Config-INI-MVP
PORTVERSION=	0.024
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Multi-value capable .ini file reader (for plugins)

BUILD_DEPENDS=	p5-Config-INI>=0:${PORTSDIR}/devel/p5-Config-INI \
		p5-Config-MVP>=0.092060:${PORTSDIR}/devel/p5-Config-MVP \
		p5-Moose>=0.65:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES
MAN3=		Config::INI::MVP::Reader.3\
		Config::MVP::Reader::INI.3

.include <bsd.port.mk>
