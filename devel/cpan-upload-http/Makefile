# New ports collection makefile for:	cpan::upload::http
# Date created:		01 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cpan-upload-http
PORTVERSION=	2.4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BR/BRADFITZ

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl script to upload one or more files to CPAN, using PAUSE

RUN_DEPENDS=	\
	p5-AppConfig-Std>=1.05:${PORTSDIR}/devel/p5-AppConfig-Std \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-Term-ReadKey>0:${PORTSDIR}/devel/p5-Term-ReadKey
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	cpan-upload-http.1

.include <bsd.port.mk>
