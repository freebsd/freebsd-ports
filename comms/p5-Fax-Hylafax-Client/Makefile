# New ports collection makefile for:	p5-Fax-Hylafax-Client
# Date created:				September 10 2005
# Whom:				Tony Shadwick <tshadwick@oss-solutions.com>
#
# $FreeBSD$
#

PORTNAME=	Fax-Hylafax-Client
PORTVERSION=	1.02
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A simple Perl client for the HylaFAX fax server

BUILD_DEPENDS=	p5-Net>=0:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	p5-Net>=0:${PORTSDIR}/net/p5-Net

PERL_CONFIGURE=	yes

MAN3=		Fax::Hylafax::Client.3

.include <bsd.port.mk>
