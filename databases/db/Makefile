PORTNAME=	db
PORTVERSION=	1.27
PORTEPOCH=	2
CATEGORIES=	databases
MASTER_SITES=	https://ftp.netbsd.org/pub/NetBSD/NetBSD-current/src/usr.bin/db/
DISTFILES=	Makefile db.c db.1
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manipulate db(3)'s btree(3) and hash(3) databases - NetBSD port

LICENSE=	BSD4CLAUSE

CFLAGS+=	-D__dead=""

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/db \
		man/man1/db.1.gz

do-extract:
	${MKDIR} ${WRKSRC}
.	for distfile in ${DISTFILES}
		${CP} ${_DISTDIR}/${distfile} ${WRKSRC}
.	endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/db ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/db.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
