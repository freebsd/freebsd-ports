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

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500007
EXTRA_PATCHES=	${FILESDIR}/extra-Dialog.xs
.endif

PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Dialog.3

.include <bsd.port.post.mk>
