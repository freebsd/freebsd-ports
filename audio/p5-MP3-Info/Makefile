# New ports collection makefile for:	p5-MP3-Info
# Date created:		14-Aug-2000
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	MP3-Info
PORTVERSION=	1.02
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=MP3
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Manipulate / fetch info from MP3 audio files

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MP3::Info.3 MPEG::MP3Info.3

.include <bsd.port.mk>
