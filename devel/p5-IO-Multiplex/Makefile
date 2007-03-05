# New ports collection makefile for:	p5-IO-Multiplex
# Date created:		04 June 2002
# Whom:	      		Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Multiplex
PORTVERSION=	1.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	IO::Multiplex - Manage IO on many file handles

PERL_CONFIGURE=	yes

MAN3=		IO::Multiplex.3

.include <bsd.port.pre.mk>

.if ( ${PERL_LEVEL} < 500805 )
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
