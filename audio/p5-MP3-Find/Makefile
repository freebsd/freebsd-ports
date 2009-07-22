# New ports collection makefile for:	p5-MP3-Find
# Date created:				2006-07-12
# Whom:					Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	MP3-Find
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Search and sort MP3 files based on their ID3 tags

RUN_DEPENDS=	p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info

MAN1=	mp3db.1 mp3find.1
MAN3=	MP3::Find::DB.3 MP3::Find::Filesystem.3 MP3::Find.3 MP3::Find::Base.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
