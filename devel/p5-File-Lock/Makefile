# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-Lock
PORTVERSION=	0.9
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl5 module for file locking (flock,fcntl)

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS+=	POLLUTE=1

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} > 501400
BROKEN=	does not compile POLLUTE is gone, no release since 1996, net/netdisco depends on me
.endif
.include <bsd.port.post.mk>
