# New ports collection makefile for:	devel/p5-IPC-PubSub
# Date created:				26 January 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IPC-PubSub
PORTVERSION=	0.26
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IPC
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Interprocess Publish/Subscribe channels

BUILD_DEPENDS=	${SITE_PERL}/DBM/Deep.pm:${PORTSDIR}/databases/p5-DBM-Deep \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/${PERL_ARCH}/Data/UUID.pm:${PORTSDIR}/devel/p5-Data-UUID
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	IPC::PubSub.3

.include <bsd.port.mk>
