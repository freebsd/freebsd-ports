# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlite-ext-miscfuncs
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
DISTNAME=	${SRCFILE}
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Math, string, and aggregate function library for SQLite

USES=		localbase sqlite
DIST_SUBDIR=	sqlite-ext

SRCFILE=	extension-functions-${PORTVERSION}.c
LIBFILE=	libsqlitemiscfuncs.so
INST_DIR=	${PREFIX}/libexec/${DIST_SUBDIR}

SUB_FILES=	${PORTDOCS}
SUB_LIST=	LIBFILE=${LIBFILE}

PLIST_FILES=	libexec/${DIST_SUBDIR}/${LIBFILE}

PORTDOCS=	README

CFLAGS+=	-fPIC -lm -shared

OPTIONS_DEFINE=	DOCS

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${SRCFILE} ${WRKSRC}/

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} ${SRCFILE} -o ${LIBFILE}

do-install:
	@${MKDIR} ${STAGEDIR}${INST_DIR}
	${INSTALL_LIB} ${WRKSRC}/${LIBFILE} ${STAGEDIR}${INST_DIR}/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
