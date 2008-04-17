# New ports collection makefile for:	PerlIO-via-Bzip2
# Date created:	   18 December 2006
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	PerlIO-via-Bzip2
PORTVERSION=	0.02
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl extension to provide a PerlIO layer to bzip2/bunzip2

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Compress/Bzip2.pm:${PORTSDIR}/archivers/p5-Compress-Bzip2
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		PerlIO::via::Bzip2.3

.include <bsd.port.mk>
