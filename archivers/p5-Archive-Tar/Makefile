# New ports collection makefile for:	p5-Archive-Tar
# Date created:				Nov 14 2000
# Whom:	      				Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	Archive-Tar
PORTVERSION=	0.22
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Archive
PKGNAMEPREFIX=	p5-

MAINTAINER=	roman@xpert.com

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib

PERL_CONFIGURE=	YES

MAN3=		Archive::Tar.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
