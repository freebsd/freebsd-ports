# New ports collection makefile for:	p5-CPANPLUS-Dist-Build
# Date created:		18 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CPANPLUS-Dist-Build
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	CPANPLUS plug-in to use Module-Build

BUILD_DEPENDS=	p5-CPANPLUS>=0.0720:${PORTSDIR}/devel/p5-CPANPLUS \
		p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Params-Check>=0.22:${PORTSDIR}/devel/p5-Params-Check \
		p5-IPC-Cmd>=0.23:${PORTSDIR}/devel/p5-IPC-Cmd \
		p5-Module-Load-Conditional>=0.06:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		p5-Module-Pluggable>=2.4:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Module-Build>=0.26.11:${PORTSDIR}/devel/p5-Module-Build
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		${PORTNAME:S/-/::/g}.3

.include <bsd.port.mk>
