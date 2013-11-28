# $FreeBSD$

PORTNAME=	audiotag
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	audio multimedia
MASTER_SITES=	GHC

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line tool for mass tagging/renaming of audio files

LICENSE=	GPLv2

OPTIONS_DEFINE=	VORBIS ID3 MP4 FLAC DOCS
OPTIONS_DEFAULT=	VORBIS ID3 MP4 FLAC

NO_BUILD=	yes

USES=		shebangfix perl5
USE_BZIP2=	yes
USE_PERL5=	run
USE_GITHUB=	yes
GH_ACCOUNT=	Daenyth
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SHEBANG_FILES=	audiotag

VORBIS_RUN_DEPENDS=	vorbiscomment:${PORTSDIR}/audio/vorbis-tools
FLAC_RUN_DEPENDS=	flac:${PORTSDIR}/audio/flac
ID3_RUN_DEPENDS=	id3tag:${PORTSDIR}/audio/id3lib
MP4_RUN_DEPENDS=	AtomicParsley:${PORTSDIR}/multimedia/atomicparsley

PORTDOCS=	COPYING ChangeLog README
PLIST_FILES=	bin/audiotag

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/audiotag ${STAGEDIR}${PREFIX}/bin

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
