# Created by: Dominik Brettnacher <domi@saargate.de>
# $FreeBSD$

PORTNAME=	Net-LibIDN
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	This module provides access to the libidn library

LIB_DEPENDS=	idn.17:${PORTSDIR}/dns/libidn

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS+=	--with-libidn=${PREFIX}/lib --with-libidn-inc=${PREFIX}/include

.include <bsd.port.mk>
