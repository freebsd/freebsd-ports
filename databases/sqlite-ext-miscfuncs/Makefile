# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlite-ext-miscfuncs
PORTVERSION=	1.1
CATEGORIES=	databases
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
DISTNAME=	${SRCFILE}
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Math, string, and aggregate function library for SQLite

USE_SQLITE=	yes
DIST_SUBDIR=	sqlite-ext
NO_WRKSUBDIR=	yes

SRCFILE=	extension-functions-${PORTVERSION}.c
LIBFILE=	libsqlitemiscfuncs.so
INST_DIR=	${PREFIX}/libexec/${DIST_SUBDIR}
USE_LDCONFIG=	${INST_DIR}

SUB_FILES=	${PORTDOCS}
SUB_LIST+=	LIBFILE=${LIBFILE}

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}/

PLIST_DIRS=	libexec/${DIST_SUBDIR}
PLIST_FILES=	${PLIST_DIRS}/${LIBFILE}

PORTDOCS=	README

CFLAGS+=	-I${PREFIX}/include -fPIC -lm -shared

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${SRCFILE} -o ${LIBFILE}

do-install:
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/libexec/${DIST_SUBDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/${LIBFILE} ${STAGEDIR}${INST_DIR}

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@${CP} ${WRKDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
