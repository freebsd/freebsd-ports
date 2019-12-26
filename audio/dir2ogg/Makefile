# Created by: chinsan
# $FreeBSD$

PORTNAME=	dir2ogg
PORTVERSION=	0.12
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://jak-linux.org/projects/dir2ogg/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line {wav,mp3,m4a} to ogg converter

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	faad:audio/faad \
		${PYTHON_PKGNAMEPREFIX}mutagen>=0:audio/py-mutagen@${PY_FLAVOR} \
		mplayer:multimedia/mplayer \
		oggenc:audio/vorbis-tools

USES=		python:2.7,run shebangfix

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
