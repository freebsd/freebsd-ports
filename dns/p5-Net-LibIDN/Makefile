# New ports collection makefile for:	p5-Net-LibIDN
# Date created:	   06 March 2004
# Whom:		   Dominik Brettnacher <domi@saargate.de>
#
# $FreeBSD$
#

PORTNAME=	Net-LibIDN
PORTVERSION=	0.09
CATEGORIES=	dns perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	domi@saargate.de
COMMENT=	This module provides access to the libidn library

LIB_DEPENDS=	idn.16:${PORTSDIR}/dns/libidn

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libidn=${PREFIX}/lib --with-libidn-inc=${PREFIX}/include

MAN3=		Net::LibIDN.3

.include <bsd.port.mk>
