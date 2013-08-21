# New ports collection makefile for:	mp3lint
# Date created:		2010-07-06
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	mp3lint
PORTVERSION=	0.9
CATEGORIES=	audio perl5
MASTER_SITES=	http://erislabs.net/ianb/projects/${PORTNAME}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A configurable tool to check collections of audio files

BUILD_DEPENDS=	libmp3-archive-perl>=0:${PORTSDIR}/audio/libmp3-archive-perl
RUN_DEPENDS=	libmp3-archive-perl>=0:${PORTSDIR}/audio/libmp3-archive-perl

USE_PERL5=	configure
USES=		perl5

MAN1=		mp3lintsum.1 mp3lintskip.1 mp3lint.1
MAN3=		mp3lint-tools.3
MAN5=		mp3lintrc.5

post-patch:
	@${REINPLACE_CMD} -e '/^DESTINSTALLSYSCONFDIR/ s|DESTDIR|PREFIX|' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
