# New ports collection makefile for:	p5-autobox-Core
# Date created:				5th March, 2010
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	autobox-Core
PORTVERSION=	1.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Core functions exposed as methods in primitive types

BUILD_DEPENDS=	p5-autobox>=0:${PORTSDIR}/devel/p5-autobox
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		autobox::Core.3

.include <bsd.port.mk>
