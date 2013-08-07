# New ports collection makefile for:	p5-Net-DAAP-Client (formerly p5-dapple)
# Date created:        27 June 2004
# Whom:                Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-DAAP-Client
PORTVERSION=	0.42
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Client for Apple iTunes DAAP service

RUN_DEPENDS=	p5-Digest-MD5-M4p>=0:${PORTSDIR}/security/p5-Digest-MD5-M4p \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Net-DAAP-DMAP>=0:${PORTSDIR}/audio/p5-Net-DAAP-DMAP
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Net::DAAP::Client.3

.include <bsd.port.mk>
