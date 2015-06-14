# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	cutmp3
PORTVERSION=	2.0.3
CATEGORIES=	audio
MASTER_SITES=	http://www.puchalla-online.de/ \
		http://mirror.mcx2.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast command line MP3 editor

USES=		tar:bzip2 readline

PLIST_FILES=	bin/cutmp3 man/man1/cutmp3.1.gz

PORTDOCS=	README README.timetable USAGE

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
