# New ports collection makefile for:	pure-sql3
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-sql3
PORTVERSION=	0.4
CATEGORIES=	databases
MASTER_SITES=	http://pure-lang.googlecode.com/files/

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure langauge binding to the SQLite3 library

LIB_DEPENDS+=	pure.7:${PORTSDIR}/lang/pure \
		sqlite3:${PORTSDIR}/databases/sqlite3

LICENSE_FILE=	${WRKSRC}/COPYING

USE_GCC=	4.2+
USE_GMAKE=	yes
PLIST_FILES=	lib/pure/sql3.pure \
		lib/pure/sql3util.so

MAKE_ARGS+=	prefix=${PREFIX} CPPFLAGS+=-I${LOCALBASE}/include \
		LDFLAGS+=-L${LOCALBASE}/lib CFLAGS="${CFLAGS}"

PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
