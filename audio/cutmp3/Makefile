PORTNAME=	cutmp3
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.3
CATEGORIES=	audio

MAINTAINER=	matthew@matthewphillips.info
COMMENT=	Small and fast command line MP3 editor
WWW=		https://github.com/tarjanm-movidius/cutmp3

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		readline
USE_GITHUB=	yes
GH_ACCOUNT=	tarjanm-movidius

PLIST_FILES=	bin/cutmp3 \
		share/man/man1/cutmp3.1.gz

PORTDOCS=	README README.timetable USAGE

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
