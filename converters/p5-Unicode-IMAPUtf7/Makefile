# New ports collection makefile for:	Unicode::IMAPUtf7
# Date created:				25 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Unicode-IMAPUtf7
PORTVERSION=	1.04
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Unicode
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MAN3=		Unicode::IMAPUtf7.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
