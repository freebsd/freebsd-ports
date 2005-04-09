# New ports collection makefile for:	p5-Dialog
# Date created:				28 Augest 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Dialog
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Dialog
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Perl interface to dialog(3)

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500600
EXTRA_PATCHES=	${FILESDIR}/extra-Dialog.xs
.endif

PERL_CONFIGURE=	yes

MAN3=		Dialog.3

.include <bsd.port.post.mk>
