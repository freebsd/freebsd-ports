# New ports collection makefile for:	p5-Dialog
# Date created:				28 Augest 2000
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Dialog
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to dialog(3)

PERL_CONFIGURE=	yes

MAN3=		Dialog.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000 && ${ARCH} == "amd64"
BROKEN=		Does not build
.endif

.include <bsd.port.post.mk>
