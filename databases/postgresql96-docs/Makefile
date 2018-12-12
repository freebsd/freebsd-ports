# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	postgresql
PORTREVISION=	2
PKGNAMESUFFIX?=	${WANT_PGSQL_VER:S,.,,}-docs

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	The PostgreSQL documentation set

MASTERDIR=	${.CURDIR}/../../databases/postgresql${WANT_PGSQL_VER:S/.//}-server
WANT_PGSQL_VER?=9.6

DISTV=		${DISTVERSION:R}

SLAVE_ONLY=	YES
COMPONENT=	-docs

PGDOCSREL?=	${DOCSDIR_REL}/release-${PGSQL_VER}
PGDOCSDIR?=	${PREFIX}/${PGDOCSREL}

sgmldir=	${LOCALBASE}/share/sgml
dbdir=		${sgmldir}/docbook

BUILD_DEPENDS+=	onsgmls:textproc/opensp			\
		openjade:textproc/openjade			\
		${sgmldir}/iso8879/catalog:textproc/iso8879	\
		${dbdir}/dsssl/modular/catalog:textproc/dsssl-docbook-modular \
		docbook-sgml>0:textproc/docbook-sgml
CONFIGURE_ARGS=	--without-readline
NO_ARCH=	yes

do-build:
	${MAKE_CMD} -C ${WRKSRC} html

do-install:
	@ ${MKDIR} ${STAGEDIR}${PGDOCSDIR}
	( cd ${WRKSRC}/doc/src/sgml/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PGDOCSDIR} )

post-install:
	@(cd ${STAGEDIR}${PREFIX} && ${FIND} ${PGDOCSREL} -type f) >> ${TMPPLIST}
	@(cd ${STAGEDIR}${PREFIX} && ${FIND} ${PGDOCSREL} -type d) | ${SORT} -r | \
	     ${SED} 's,.*,@unexec rmdir %D/& 2>/dev/null || true,' >>${TMPPLIST}

.include "${MASTERDIR}/Makefile"
