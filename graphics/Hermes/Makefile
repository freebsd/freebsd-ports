# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	Hermes
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.su.se/pub/lunar/source-archive/ \
		GENTOO
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Fast pixel formats conversion library

USE_BZIP2=	yes
USES=		gmake
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
CFLAGS+=	-w
USE_LDCONFIG=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog FAQ README TODO TODO.conversion

DOCSRCDIR2=	${WRKSRC}/docs/api
DOCSDIR2=	${DOCSDIR}/docs/api
DOC_FILES2=	*.htm api.ps api.txt

DOCSRCDIR3=	${WRKSRC}/docs/api/sgml
DOCSDIR3=	${DOCSDIR}/docs/api/sgml
DOC_FILES3=	api.sgml

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == sparc64
IGNORE=		is broken on sparc64: interchanges red and blue colour channels in images
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR3}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}${DOCSDIR3}

.include <bsd.port.post.mk>
