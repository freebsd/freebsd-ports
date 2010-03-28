# New ports collection makefile for: dir2ogg
# Date created:		2008/01/26
# Whom:			chinsan
#
# $FreeBSD$
#

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

MAN1=		${PORTNAME}.1
PORTDOCS=	NEWS README
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e \
		'/^#!/s|/.*python|${SETENV} python|g' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
