# New ports collection makefile for:	p5-orz
# Date created:				2006-06-08
# Whom:					Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	orz
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN/INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	A method of annotation as /* */ in perl

BUILD_DEPENDS=	p5-Module-Compile>=0.21:${PORTSDIR}/devel/p5-Module-Compile
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		orz.3

.include <bsd.port.mk>
