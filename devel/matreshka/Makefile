# Created by: John Marino <draco@marino.st>
# $FreeBSD$

PORTNAME=	matreshka
PORTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	http://forge.ada-ru.org/matreshka/downloads/

MAINTAINER=	draco@marino.st
COMMENT=	Ada framework for information systems development

LICENSE=	BSD

BUILD_DEPENDS=	gprbuild>=20120510:${PORTSDIR}/devel/gprbuild

USES=		ada
USE_GMAKE=	yes
DESTINY=	${WRKDIR}/destino

OPTIONS_DEFINE=	SQLITE3 FIREBIRD PGSQL MYSQL ORACLE AMF
OPTIONS_DEFAULT=SQLITE3 FIREBIRD PGSQL MYSQL

AMF_DESC=	Build Ada Modeling Framework

MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	SMP_MFLAGS=-j${MAKE_JOBS_NUMBER} \
		DESTDIR=${DESTINY}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFIREBIRD}
MAKE_ENV+= HAS_FIREBIRD=yes
.endif

.if ${PORT_OPTIONS:MMYSQL}
MAKE_ENV+= HAS_MYSQL=yes
.endif

.if ${PORT_OPTIONS:MORACLE}
MAKE_ENV+= HAS_OCI=yes
.endif

.if ${PORT_OPTIONS:MPGSQL}
MAKE_ENV+= HAS_POSTGRESQL=yes
.endif

.if ${PORT_OPTIONS:MSQLITE3}
MAKE_ENV+= HAS_SQLITE3=yes
.endif

.if ${PORT_OPTIONS:MAMF}
MAKE_ENV+= WANT_AMF=yes
.endif

post-install:
	${CP} -pR ${DESTINY}${PREFIX}/ ${PREFIX}/
	@cd ${DESTINY}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} > ${WRKDIR}/PLIST.all
	@cd ${DESTINY}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | ${SORT} -r | \
	   ${SED} -e '/lib\/gnat$$/d' -e 's/^/@dirrm /g' >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@${CAT} ${WRKDIR}/PLIST.all >> ${TMPPLIST}

.include <bsd.port.mk>
