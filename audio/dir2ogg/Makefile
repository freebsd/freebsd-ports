# Created by: chinsan
# $FreeBSD$

PORTNAME=	dir2ogg
PORTVERSION=	0.11.8
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://jak-linux.org/projects/dir2ogg/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line {wav,mp3,m4a} to ogg converter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	faad:audio/faad \
		mutagen-inspect:audio/py-mutagen \
		mplayer:multimedia/mplayer \
		oggenc:audio/vorbis-tools

USES=		python:2,run shebangfix

SHEBANG_FILES=	${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	NEWS README
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
