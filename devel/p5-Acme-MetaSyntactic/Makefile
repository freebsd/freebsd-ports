# New ports collection makefile for:	devel/p5-Acme-MetaSyntactic
# Date created:				27 April 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Acme-MetaSyntactic
PORTVERSION=	0.99
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Themed metasyntactic variables names

RUN_DEPENDS=	p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

.include "Makefile.man"
.include <bsd.port.mk>
