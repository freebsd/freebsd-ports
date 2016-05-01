# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	matreshka
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://forge.ada-ru.org/matreshka/downloads/

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada framework for information systems development

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	gprbuild:devel/gprbuild

USES=		ada gmake pkgconfig
HAS_CONFIGURE=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	SQLITE3 FIREBIRD PGSQL MYSQL ORACLE AMF
OPTIONS_DEFAULT=SQLITE3 PGSQL

AMF_DESC=	Build Ada Modeling Framework

SQLITE3_CONFIGURE_ENABLE=	sqlite3
FIREBIRD_CONFIGURE_ENABLE=	firebird
PGSQL_CONFIGURE_ENABLE=		postgresql
MYSQL_CONFIGURE_ENABLE=		mysql
ORACLE_CONFIGURE_ENABLE=	oracle
AMF_CONFIGURE_ENABLE=		amf

MYSQL_USE=			MYSQL=yes
PGSQL_USES=			pgsql
SQLITE3_USES=			sqlite
FIREBIRD_USES=			firebird

MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	SMP_MFLAGS=-j${MAKE_JOBS_NUMBER}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFIREBIRD}
CONFIGURE_ARGS+= --with-firebird-libdir=${LOCALBASE}/lib
.endif

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_CMD} config

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so \
		${STAGEDIR}${PREFIX}/bin/wsdl2ada
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>
