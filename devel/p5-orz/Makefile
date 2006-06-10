# New ports collection makefile for:	p5-orz
# Date created:				2006-06-08
# Whom:					Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	orz
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CPAN/INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	A method of annotation as /* */ in perl

BUILD_DEPENDS=	${SITE_PERL}/Module/Compile.pm:${PORTSDIR}/devel/p5-Module-Compile
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		orz.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or above
.endif

.include <bsd.port.post.mk>
