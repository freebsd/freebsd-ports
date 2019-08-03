# $FreeBSD$

PORTNAME=	audiotag
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	audio multimedia
MASTER_SITES=	GHC

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line tool for mass tagging/renaming of audio files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		unfetchable

USE_GITHUB=	yes
GH_ACCOUNT=	Daenyth

USES=		tar:bzip2 shebangfix perl5
USE_PERL5=	run

NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	audiotag

PORTDOCS=	COPYING ChangeLog README
PLIST_FILES=	bin/audiotag

OPTIONS_DEFINE=	VORBIS ID3 MP4 FLAC DOCS
OPTIONS_DEFAULT=	VORBIS ID3 MP4 FLAC

VORBIS_RUN_DEPENDS=	vorbiscomment:audio/vorbis-tools
FLAC_RUN_DEPENDS=	flac:audio/flac
ID3_RUN_DEPENDS=	id3tag:audio/id3lib
MP4_RUN_DEPENDS=	AtomicParsley:multimedia/atomicparsley

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/audiotag ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
