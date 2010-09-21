# New ports collection makefile for:	p5-Digest-TransformPath
# Date created:				08 September 2007
# Whom:					Cory R. King <coryking@mozimedia.com>
#
# $FreeBSD$
#

PORTNAME=	Digest-TransformPath
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	Implements the TransformPath concept

PERL_CONFIGURE=	yes

MAN3=		Digest::TransformPath.3

test:	build
	(@cd ${WRKSRC} && make test)

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500809
RUN_DEPENDS+=	p5-Digest-MD5>=2.36:${PORTSDIR}/security/p5-Digest-MD5
BUILD_DEPENDS+=	p5-Digest-MD5>=2.36:${PORTSDIR}/security/p5-Digest-MD5
.endif

.include <bsd.port.post.mk>
