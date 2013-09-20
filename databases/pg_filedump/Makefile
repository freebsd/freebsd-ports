# $FreeBSD$

PORTNAME=	pg_filedump
PORTVERSION=	8.4
CATEGORIES=	databases
MASTER_SITES=	http://sources.redhat.com/rhdb/tools/
EXTRACT_SUFX=	.tar

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Utility to format PostgreSQL heap, index, etc into human-readable form

FETCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/databases/postgresql84-client:patch
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/databases/postgresql84-client:patch

WRKSRC=	${WRKDIR}/${PORTNAME}-8.4.0

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

PG84VER!=	cd ${PORTSDIR}/databases/postgresql84-client && ${MAKE} -V PORTVERSION

post-patch:
	${REINPLACE_CMD} -e "s|8.4.0|${PG84VER}|" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pg_filedump ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.pg_filedump ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
