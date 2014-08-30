# Created by: Dominik Brettnacher <domi@saargate.de>
# $FreeBSD$

PORTNAME=	Net-LibIDN
PORTVERSION=	0.12
PORTREVISION=	2
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	This module provides access to the libidn library

LICENSE=	ART10

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	--with-libidn=${LOCALBASE}/lib \
		--with-libidn-inc=${LOCALBASE}/include

.include <bsd.port.mk>
