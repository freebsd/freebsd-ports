# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	matreshka
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://forge.ada-ru.org/matreshka/downloads/

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada framework for information systems development

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	gprbuild>=20120510:${PORTSDIR}/devel/gprbuild

USES=		ada gmake pkgconfig
HAS_CONFIGURE=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	SQLITE3 FIREBIRD PGSQL MYSQL ORACLE AMF
OPTIONS_DEFAULT=SQLITE3 FIREBIRD PGSQL MYSQL

AMF_DESC=	Build Ada Modeling Framework

SQLITE3_CONFIGURE_ENABLE=	sqlite3
FIREBIRD_CONFIGURE_ENABLE=	firebird
PGSQL_CONFIGURE_ENABLE=		postgresql
MYSQL_CONFIGURE_ENABLE=		mysql
ORACLE_CONFIGURE_ENABLE=	oracle
AMF_CONFIGURE_ENABLE=		amf

MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	SMP_MFLAGS=-j${MAKE_JOBS_NUMBER}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFIREBIRD}
CONFIGURE_ARGS+= --with-firebird-libdir=${LOCALBASE}/lib
USE_FIREBIRD= yes
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL= yes
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL= yes
.endif

.if ${PORT_OPTIONS:MSQLITE3}
USE_SQLITE= yes
.endif

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_CMD} config

post-install:
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | ${SORT} -r | \
	   ${SED} -e '/lib\/gnat$$/d' -e 's/^/@dirrm /g' >> ${TMPPLIST}
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
