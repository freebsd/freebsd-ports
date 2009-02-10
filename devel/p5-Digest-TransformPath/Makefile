# New ports collection makefile for:	p5-Digest-TransformPath
# Date created:				08 September 2007
# Whom:					Cory R. King <coryking@mozimedia.com>
#
# $FreeBSD$
#

PORTNAME=	Digest-TransformPath
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	Implements the TransformPath concept

BUILD_DEPENDS=	p5-Digest-MD5>=2.36:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	p5-Digest-MD5>=2.36:${PORTSDIR}/security/p5-Digest-MD5

PERL_CONFIGURE=	yes

MAN3=		Digest::TransformPath.3

test:	build
	(@cd ${WRKSRC} && make test)

.include <bsd.port.mk>
