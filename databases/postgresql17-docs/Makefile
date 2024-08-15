PORTNAME=	postgresql
PORTREVISION=	0
PKGNAMESUFFIX?=	${WANT_PGSQL_VER:S,.,,}-docs

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	The PostgreSQL documentation set

MASTERDIR=	${.CURDIR}/../../databases/postgresql${WANT_PGSQL_VER}-server
WANT_PGSQL_VER?=17

DISTV=		${DISTVERSION:R}

SLAVE_ONLY=	YES
COMPONENT=	-docs

PGDOCSREL?=	${DOCSDIR_REL}/release-${WANT_PGSQL_VER}
PGDOCSDIR?=	${PREFIX}/${PGDOCSREL}

BUILD_DEPENDS+=	docbook-xml>0:textproc/docbook-xml \
		docbook-xsl>=0:textproc/docbook-xsl \
		fop:textproc/fop \
		xmllint:textproc/libxml2 \
		xsltproc:textproc/libxslt

CONFIGURE_ARGS=	--without-readline --without-icu
NO_ARCH=	yes

do-build:
	${MAKE_CMD} -C ${WRKSRC} html

do-install:
	@ ${MKDIR} ${STAGEDIR}${PGDOCSDIR}
	( cd ${WRKSRC}/doc/src/sgml/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PGDOCSDIR} )

post-install:
	@(cd ${STAGEDIR}${PREFIX} && ${FIND} ${PGDOCSREL} -type f) >> ${TMPPLIST}

.include "${MASTERDIR}/Makefile"
