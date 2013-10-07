# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	postgresql
PORTREVISION=	0
PKGNAMESUFFIX?=	${DISTV:S/.//}-docs
DISTV=	${DISTVERSION:R}

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	The PostgreSQL documentation set

MASTERDIR=	${.CURDIR}/../../databases/postgresql${WANT_PGSQL_VER}-server

USE_PGSQL=	YES
WANT_PGSQL_VER?=91

SLAVE_ONLY=	YES

PGDOCSREL?=	${DOCSDIR_REL}/release-${PGSQL_VER}
PGDOCSDIR?=	${PREFIX}/${PGDOCSREL}

sgmldir=	${LOCALBASE}/share/sgml
dbdir=		${sgmldir}/docbook

BUILD_DEPENDS+=	onsgmls:${PORTSDIR}/textproc/opensp			\
		openjade:${PORTSDIR}/textproc/openjade			\
		${sgmldir}/iso8879/catalog:${PORTSDIR}/textproc/iso8879	\
		${dbdir}/dsssl/modular/catalog:${PORTSDIR}/textproc/dsssl-docbook-modular \
		${dbdir}/4.2/docbook.dtd:${PORTSDIR}/textproc/docbook-420

NO_STAGE=	yes
do-build:
	${GMAKE} -C ${WRKSRC} html

do-install:
	@ $(MKDIR) ${PGDOCSDIR}
	( cd ${WRKSRC}/doc/src/sgml/html && \
		${COPYTREE_SHARE} \* ${PGDOCSDIR} )

post-install:
	@(cd ${PREFIX} && ${FIND} ${PGDOCSREL} -type f) >> ${TMPPLIST}
	@(cd ${PREFIX} && ${FIND} ${PGDOCSREL} -type d) | ${SORT} -r | \
	     ${SED} 's,.*,@unexec rmdir %D/& 2>/dev/null || true,' >>${TMPPLIST}
	

.include "${MASTERDIR}/Makefile"
