# New ports collection makefile for:	cpan-upload
# Date created:				Nov 30 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	cpan-upload
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/N/NE/NEILB/scripts

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Script for uploading distributions to CPAN

RUN_DEPENDS=	p5-AppConfig-Std>=1.05:${PORTSDIR}/devel/p5-AppConfig-Std \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	cpan-upload.1

.include <bsd.port.mk>
