# New ports collection makefile for:	mpegaudio
# Date created:		1 July 1996
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	mpegaudio
PORTVERSION=	3.9
CATEGORIES=	audio
MASTER_SITES=	http://www.iuma.com/IUMA/ftp/audio_utils/converters/source/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	torstenb@FreeBSD.org

MAN1=		mpeg_musicin.1 mpeg_musicout.1

post-install:
	${INSTALL_MAN} ${FILESDIR}/mpeg_musicin.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${FILESDIR}/mpeg_musicout.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
