# New ports collection makefile for:	p5-Unicode-String
# Date created:				10th September 2000
# Whom:					Ilia Chipitsine <ilia@jane.cgu.chel.su>
#
# $FreeBSD$
#

PORTNAME=	Unicode-String
PORTVERSION=	2.07
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Unicode
PKGNAMEPREFIX=	p5-

MAINTAINER=	ilia@cgu.chel.su
COMMENT=	These are experimental Perl5 modules to handle various Unicode issues

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

PERL_CONFIGURE=	yes

MAN3=		Unicode::CharName.3 Unicode::String.3

.include <bsd.port.mk>
