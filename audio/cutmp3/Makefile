# New ports collection makefile for:	cutmp3
# Date created:				05 Oct 2008
# Whom:					Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	cutmp3
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	http://www.puchalla-online.de/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A small and fast command line MP3 editor

USE_BZIP2=	yes
MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/cutmp3

PORTDOCS=	README README.timetable USAGE

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
