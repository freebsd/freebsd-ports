# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	cutmp3
PORTVERSION=	2.0.3
CATEGORIES=	audio
MASTER_SITES=	http://www.puchalla-online.de/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A small and fast command line MP3 editor

NO_STAGE=	yes
USE_BZIP2=	yes
MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/cutmp3

PORTDOCS=	README README.timetable USAGE

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
