# Created by: Edwin Groothuis (edwin@mavetju.org)
# $FreeBSD$

PORTNAME=	db
PORTVERSION=	1.14
PORTEPOCH=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manipulate db(3)'s btree(3) and hash(3) databases - NetBSD port

LICENSE=	BSD4CLAUSE

USES=		uidfix
MAKE_ENV=	BINDIR=${PREFIX}/bin SHAREDIR=${PREFIX}

DIST_CVS=	http://cvsweb.netbsd.org/bsdweb.cgi/~checkout~/src/usr.bin/db/db
DB1VERSION=	1.19
MAKEVERSION=	1.2
DIST_DB1=	http://cvsweb.netbsd.org/bsdweb.cgi/~checkout~/src/usr.bin/db/db.1?rev=${DB1VERSION}&content-type=text/plain&only_with_tag=HEAD
DIST_DBC=	http://cvsweb.netbsd.org/bsdweb.cgi/~checkout~/src/usr.bin/db/db.c?rev=${PORTVERSION}&content-type=text/plain
DIST_MAKEFILE=	http://cvsweb.netbsd.org/bsdweb.cgi/~checkout~/src/usr.bin/db/Makefile?rev=${MAKEVERSION}&content-type=text/plain

PLIST_FILES=	bin/db \
		man/man1/db.1.gz
tarball:
	${MKDIR} ${WRKSRC}
	fetch -o ${WRKSRC}/db.1 "${DIST_DB1}"
	fetch -o ${WRKSRC}/db.c "${DIST_DBC}"
	fetch -o ${WRKSRC}/Makefile "${DIST_MAKEFILE}"
	cd ${WRKDIR} && ${TAR} zcvf ${DISTFILES} ${PORTNAME}-${PORTVERSION}
	${MV} ${WRKDIR}/${DISTFILES} ${DISTDIR}

.include <bsd.port.mk>
