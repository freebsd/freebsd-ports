# New ports collection makefile for:	devel/p5-Module-CoreList
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Module-CoreList
PORTVERSION=	2.57
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	See what modules shipped with versions of perl

PERL_CONFIGURE=	yes

MAN3=		Module::CoreList.3

post-patch:
	@${REINPLACE_CMD} -e '/corelist/d' ${WRKSRC}/Makefile.PL

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

.include <bsd.port.mk>
