# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	sqlite-ext-spellfix
PORTVERSION=	3.8.11.1
CATEGORIES=	databases
MASTER_SITES=	https://www.sqlite.org/2015/ http://www2.sqlite.org/2015/ http://www3.sqlite.org/2015/
DISTNAME=	sqlite-src-${PORTVERSION:S|8.|8|:S|.|0|g}
DIST_SUBDIR=	sqlite-ext

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Search large vocabulary for close matches for SQLite

LICENSE=	public
LICENSE_NAME=	Public Domain
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://www.sqlite.org/copyright.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		sqlite:3 zip
NO_WRKSUBDIR=	yes

SRCFILE=	${DISTNAME}/ext/misc/spellfix.c
LIBFILE=	libspellfix.so
INST_DIR=	${PREFIX}/libexec/${DIST_SUBDIR}
USE_LDCONFIG=	${INST_DIR}

EXTRACT_AFTER_ARGS=	${SRCFILE}

PLIST_FILES=	libexec/${DIST_SUBDIR}/${LIBFILE}

CFLAGS+=	-I${PREFIX}/include -fPIC -shared

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} ${SRCFILE} -o ${LIBFILE}

do-install:
	${INSTALL} -d ${STAGEDIR}${PREFIX}/libexec/${DIST_SUBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${LIBFILE} ${STAGEDIR}${INST_DIR}

.include <bsd.port.mk>
