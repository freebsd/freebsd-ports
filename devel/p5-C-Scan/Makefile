# New ports collection makefile for:	p5-C-Scan
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	C-Scan
PORTVERSION=	0.74
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	C
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module to scan C language files for easily recognized constructs

BUILD_DEPENDS=	${SITE_PERL}/Data/Flow.pm:${PORTSDIR}/devel/p5-Data-Flow

PERL_CONFIGURE=	yes

MAN3=		C::Scan.3

.include <bsd.port.mk>
