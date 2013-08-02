# New ports collection makefile for:	p5-UUID-Tiny
# Date created:		2009-09-15
# Whom:			Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	UUID-Tiny
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure Perl UUID Support With Functional Interface

BUILD_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		UUID::Tiny.3

.include <bsd.port.mk>
