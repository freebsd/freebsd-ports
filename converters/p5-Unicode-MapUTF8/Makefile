# New ports collection makefile for:	p5-Unicode-MapUTF8
# Date created:				28 February 2002
# Whom:					Ryan T. Dean <rtdean@cytherianage.net>
#
# $FreeBSD$

PORTNAME=	Unicode-MapUTF8
PORTVERSION=	1.09
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Unicode
PKGNAMEPREFIX=	p5-

MAINTAINER=	rtdean@cytherianage.net

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Unicode/Map.pm:${PORTSDIR}/converters/p5-Unicode-Map \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Unicode/Map8.pm:${PORTSDIR}/converters/p5-Unicode-Map8 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Unicode::MapUTF8.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
