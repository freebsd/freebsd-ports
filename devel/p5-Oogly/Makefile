# New ports collection makefile for:	p5-Oogly
# Date created:	   20 Dec 2010
# Whom:		   Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	Oogly
PORTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AWNCORP
PKGNAMEPREFIX=	p5-

MAINTAINER=	magik@roorback.net
COMMENT=	A Data validation idea that just might be ideal

BUILD_DEPENDS=	p5-Array-Unique>0:${PORTSDIR}/devel/p5-Array-Unique \
		p5-Data-Dumper-Concise>0:${PORTSDIR}/devel/p5-Data-Dumper-Concise \
		p5-Hash-Merge>=0.11:${PORTSDIR}/textproc/p5-Hash-Merge
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Oogly.3

.include <bsd.port.mk>
