# New ports collection makefile for:	Data::TemporaryBag
# Date created:		30 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Data-TemporaryBag
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Handle long size data using temporary file

PERL_CONFIGURE=	yes

MAN3=		Data::TemporaryBag.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${PATCHDIR}/500503-TemporaryBag.pm
.endif
.endif

.include <bsd.port.post.mk>
