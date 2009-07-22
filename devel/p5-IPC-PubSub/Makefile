# New ports collection makefile for:	devel/p5-IPC-PubSub
# Date created:				26 January 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IPC-PubSub
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Interprocess Publish/Subscribe channels

BUILD_DEPENDS=	p5-DBM-Deep>=1:${PORTSDIR}/databases/p5-DBM-Deep \
		p5-Time-HiRes>0:${PORTSDIR}/devel/p5-Time-HiRes \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Data-UUID>0:${PORTSDIR}/devel/p5-Data-UUID
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	IPC::PubSub.3

.include <bsd.port.mk>
