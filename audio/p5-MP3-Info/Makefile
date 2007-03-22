# New ports collection makefile for:	p5-MP3-Info
# Date created:		14-Aug-2000
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	MP3-Info
PORTVERSION=	1.22
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=MP3
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Manipulate / fetch info from MP3 audio files

PERL_CONFIGURE=	yes

MAN3=		MP3::Info.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6.0
.endif

.include <bsd.port.post.mk>
