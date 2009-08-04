# New ports collection makefile for:	devel/p5-B-Hooks-OP-PPAddr
# Date created:				04 August 2009
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	B-Hooks-OP-PPAddr
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	B
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Hook into opcode execution

BUILD_DEPENDS=	p5-parent>0:${PORTSDIR}/devel/p5-parent \
		p5-ExtUtils-Depends>=0.302:${PORTSDIR}/devel/p5-ExtUtils-Depends
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	B::Hooks::OP::PPAddr.3

.include <bsd.port.mk>
