# New ports collection makefile for:	devel/p5-Rose-DateTime
# Date created:				09 June 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Rose-DateTime
PORTVERSION=	0.534
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DateTime helper functions and objects

BUILD_DEPENDS=	p5-Rose-Object>=0.82:${PORTSDIR}/devel/p5-Rose-Object \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Rose::DateTime.3 \
	Rose::DateTime::Parser.3 \
	Rose::DateTime::Util.3

.include <bsd.port.mk>
