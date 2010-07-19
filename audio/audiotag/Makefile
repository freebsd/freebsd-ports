# New ports collection makefile for:	audiotag
# Date created:		2008-04-08
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	audiotag
PORTVERSION=	0.19
CATEGORIES=	audio multimedia
MASTER_SITES=	 http://cloud.github.com/downloads/Daenyth/audiotag/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	A command-line tool for mass tagging/renaming of audio files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS=	VORBIS "Support renaming/tagging ogg vorbis files" On \
		ID3 "Support renaming/tagging files supporting id3 tags" On \
		MP4 "Support renaming/tagging mp4 files" On

USE_PERL5_RUN=	yes

NO_BUILD=	yes

USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_VORBIS)
RUN_DEPENDS+=	vorbiscomment:${PORTSDIR}/audio/vorbis-tools
.endif
.if defined(WITH_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif
.if defined(WITH_ID3)
RUN_DEPENDS+=	id3tag:${PORTSDIR}/audio/id3lib
.endif
.if defined(WITH_MP4)
RUN_DEPENDS+=	AtomicParsley:${PORTSDIR}/multimedia/atomicparsley
.endif

PORTDOCS=	COPYING ChangeLog README
PLIST_FILES=	bin/audiotag

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/audiotag ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
