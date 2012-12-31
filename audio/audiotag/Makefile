# $FreeBSD$

PORTNAME=	audiotag
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	audio multimedia
MASTER_SITES=	GHC

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	A command-line tool for mass tagging/renaming of audio files

LICENSE=	GPLv2

OPTIONS_DEFINE=	VORBIS ID3 MP4 FLAC DOCS
OPTIONS_DEFAULT=	VORBIS ID3 MP4 FLAC

NO_BUILD=	yes

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Daenyth

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVORBIS}
RUN_DEPENDS+=	vorbiscomment:${PORTSDIR}/audio/vorbis-tools
.endif
.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif
.if ${PORT_OPTIONS:MID3}
RUN_DEPENDS+=	id3tag:${PORTSDIR}/audio/id3lib
.endif
.if ${PORT_OPTIONS:MMP4}
RUN_DEPENDS+=	AtomicParsley:${PORTSDIR}/multimedia/atomicparsley
.endif

PORTDOCS=	COPYING ChangeLog README
PLIST_FILES=	bin/audiotag

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/audiotag ${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
