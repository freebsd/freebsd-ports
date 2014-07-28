# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	Hermes
PORTVERSION=	1.3.3
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.su.se/pub/lunar/source-archive/ \
		GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast pixel formats conversion library

USES=		gmake libtool tar:bzip2
USE_AUTOTOOLS=	libtoolize
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
USE_LDCONFIG=	yes

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

.include <bsd.port.pre.mk>

.if ${ARCH} == sparc64
IGNORE=		is broken on sparc64: interchanges red and blue colour channels in images
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.1

	@${MKDIR} ${STAGEDIR}${DOCSDIR3}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}${DOCSDIR3}

.include <bsd.port.post.mk>
