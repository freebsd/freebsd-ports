# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	Hermes
PORTVERSION=	1.3.3
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.su.se/pub/lunar/source-archive/ \
		GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast pixel formats conversion library

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool tar:bzip2
USE_LDCONFIG=	yes
LDFLAGS_i386=	-Wl,-znotext

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog FAQ README

DOCSRCDIR2=	${WRKSRC}/docs/api
DOCSDIR2=	${DOCSDIR}/docs/api
DOC_FILES2=	*.htm api.ps api.txt

DOCSRCDIR3=	${WRKSRC}/docs/api/sgml
DOCSDIR3=	${DOCSDIR}/docs/api/sgml
DOC_FILES3=	api.sgml

OPTIONS_DEFINE=	DOCS

BROKEN_sparc64=		interchanges red and blue colour channels in images

post-extract:
	${TOUCH} ${WRKSRC}/src/hrconfig.h.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR3}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}${DOCSDIR3}

.include <bsd.port.mk>
