# $FreeBSD$

PORTNAME=	sqlite-ext-pcre
PORTVERSION=	20100208
CATEGORIES=	databases

MAINTAINER=	vivek@khera.org
COMMENT=	Regexp function for SQLite based on PCRE library

LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre

USE_SQLITE=	yes
DIST_SUBDIR=	sqlite-ext

LIBFILE=	pcre.so
INST_DIR=	${PREFIX}/libexec/${DIST_SUBDIR}
USE_LDCONFIG=	${INST_DIR}

SUB_LIST+=	LIBFILE=${LIBFILE}

PLIST_DIRS=	libexec/${DIST_SUBDIR}
PLIST_FILES=	${PLIST_DIRS}/${LIBFILE}

USES=		gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ralight
GH_PROJECT=	sqlite3-pcre
GH_COMMIT=	c98da41
GH_TAGNAME=	${GH_COMMIT}

do-build:
	@cd ${WRKSRC} && ${GMAKE}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${DIST_SUBDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/${LIBFILE} ${STAGEDIR}${PREFIX}/libexec/${DIST_SUBDIR}

.include <bsd.port.mk>
