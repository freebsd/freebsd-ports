# New ports collection makefile for:	ExtUtils::ParseXS
# Date created:				29 June 2003
# Whom:                			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-ParseXS
PORTVERSION=	2.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ExtUtils
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Converts Perl XS code into C code

PERL_CONFIGURE=	yes
MAN3=		ExtUtils::ParseXS.3

pre-patch:
	@${PERL} -pi -e 's/INSTALLDIRS/bebe/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
