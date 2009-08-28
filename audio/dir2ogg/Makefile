# New ports collection makefile for: dir2ogg
# Date created:		2008/01/26
# Whom:			chinsan
#
# $FreeBSD$
#

PORTNAME=	dir2ogg
PORTVERSION=	0.11.6
CATEGORIES=	audio
MASTER_SITES=	http://jak-linux.org/projects/dir2ogg/0.11/ \
		LOCAL/chinsan/dir2ogg

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line {wav,mp3,m4a} to ogg converter

RUN_DEPENDS=	faad:${PORTSDIR}/audio/faad \
		mutagen-inspect:${PORTSDIR}/audio/py-mutagen \
		mplayer:${PORTSDIR}/multimedia/mplayer

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/dir2ogg
.if !defined(NOPORTDOCS)
PLIST_DIRS=	${DOCSDIR_REL}
PLIST_FILES+=	${DOCSDIR_REL}/README \
		${DOCSDIR_REL}/NEWS
.endif

DOCS=		README NEWS
MAN1=		dir2ogg.1

post-patch:
	@${REINPLACE_CMD} -e '1 s/python/env python/' ${WRKSRC}/dir2ogg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dir2ogg ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dir2ogg.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

post-install:
	@${ECHO} "dir2ogg is now installed. Enjoy..."

.include <bsd.port.mk>
