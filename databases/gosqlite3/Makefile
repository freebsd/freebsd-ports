# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	gosqlite3
PORTVERSION=	20120330
CATEGORIES=	databases
MASTER_SITES=	LOCAL/jlaffaye

MAINTAINER=	lichray@gmail.com
COMMENT=	A Go interface for SQLite3

LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3

GO_PKGNAME=	${SUBLIBDIR}/${PORTNAME}

SUBLIBDIR=	github.com/kuroneko

NO_STAGE=	yes
do-install:
	${MKDIR} ${GO_LOCAL_LIBDIR}/${SUBLIBDIR}
	${INSTALL_DATA} ${GO_WRKDIR_PKG}/${SUBLIBDIR}/gosqlite3.a ${GO_LOCAL_LIBDIR}/${SUBLIBDIR}
	${MKDIR} ${GO_LOCAL_SRCDIR}/${GO_PKGNAME}
	(cd ${GO_WRKSRC}/ && ${COPYTREE_SHARE} \* ${GO_LOCAL_SRCDIR}/${GO_PKGNAME})

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
