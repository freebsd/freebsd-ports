# New ports collection makefile for:	p5-Tie-ShareLite
# Date created:				21 Dec 2005
# Whom:	      				jnlin@csie.nctu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	Tie-ShareLite
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Tied hash interface to IPC::ShareLite

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IPC/ShareLite.pm:${PORTSDIR}/devel/p5-IPC-ShareLite

PERL_CONFIGURE=	yes

MAN3=		Tie::ShareLite.3

.include <bsd.port.mk>
