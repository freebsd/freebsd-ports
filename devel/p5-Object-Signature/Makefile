# New ports collection makefile for:	p5-Object-Signature
# Date created:	   26 Dec 2005
# Whom:		   Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Object-Signature
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Object
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Generate cryptographic signatures for objects

BUILD_DEPENDS=	p5-Storable>=2.11:${PORTSDIR}/devel/p5-Storable \
		p5-Digest-MD5>=2.00:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Test-Simple>=0.47:${PORTSDIR}/devel/p5-Test-Simple \
		p5-PathTools>=0.80:${PORTSDIR}/devel/p5-PathTools \
		p5-ExtUtils-AutoInstall>=0.63:${PORTSDIR}/devel/p5-ExtUtils-AutoInstall
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Object::Signature.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.0 or higher. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
