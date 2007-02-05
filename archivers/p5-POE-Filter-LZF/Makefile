# New ports collection makefile for:	p5-POE-Filter-LZF
# Date created:		2006-09-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-LZF
PORTVERSION=	1.6.0
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A POE filter wrapped around Compress::LZF

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Compress/LZF.pm:${PORTSDIR}/archivers/p5-Compress-LZF \
		p5-POE>=0.3501:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Filter::LZF.3

.include <bsd.port.mk>
