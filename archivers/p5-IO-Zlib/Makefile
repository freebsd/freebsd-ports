# New ports collection makefile for:	IO::Zlib
# Date created:		15 Feb 2002
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Zlib
PORTVERSION=	1.10
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	IO:: style interface to Compress::Zlib

BUILD_DEPENDS=	p5-Compress-Zlib>=2:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS=	p5-Compress-Zlib>=2:${PORTSDIR}/archivers/p5-Compress-Zlib

PERL_CONFIGURE=	yes
MAN3=		IO::Zlib.3

.include <bsd.port.mk>
