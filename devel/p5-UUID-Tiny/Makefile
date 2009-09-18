# New ports collection makefile for:	p5-UUID-Tiny
# Date created:		2009-09-15
# Whom:			Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	UUID-Tiny
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cjk32@cam.ac.uk
COMMENT=	Pure Perl UUID Support With Functional Interface

BUILD_DEPENDS=	p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		UUID::Tiny.3

.include <bsd.port.mk>
