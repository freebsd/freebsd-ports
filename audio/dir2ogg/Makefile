# Created by: chinsan
# $FreeBSD$

PORTNAME=	dir2ogg
PORTVERSION=	0.11.8
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://jak-linux.org/projects/dir2ogg/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line {wav,mp3,m4a} to ogg converter

RUN_DEPENDS=	faad:${PORTSDIR}/audio/faad \
		mutagen-inspect:${PORTSDIR}/audio/py-mutagen \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		oggenc:${PORTSDIR}/audio/vorbis-tools

USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	NEWS README
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		'/^#!/s|/.*python|${SETENV} python|g' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
