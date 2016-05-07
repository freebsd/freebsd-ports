# $FreeBSD$

PORTNAME=	sqlite-ext-pcre
PORTVERSION=	20100208
CATEGORIES=	databases

MAINTAINER=	vivek@khera.org
COMMENT=	Regexp function for SQLite based on PCRE library

LIB_DEPENDS+=	libpcre.so:devel/pcre

DIST_SUBDIR=	sqlite-ext

LIBFILE=	pcre.so
INST_DIR=	${PREFIX}/libexec/${DIST_SUBDIR}
USE_LDCONFIG=	${INST_DIR}

SUB_LIST+=	LIBFILE=${LIBFILE}

PLIST_FILES=	libexec/${DIST_SUBDIR}/${LIBFILE}

USES=		gmake pkgconfig sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	ralight
GH_PROJECT=	sqlite3-pcre
GH_TAGNAME=	c98da41

do-build:
	@cd ${WRKSRC} && ${GMAKE}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${DIST_SUBDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/${LIBFILE} ${STAGEDIR}${PREFIX}/libexec/${DIST_SUBDIR}

.include <bsd.port.mk>
