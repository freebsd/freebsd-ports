PORTNAME=	pgagroal
DISTVERSION=	1.6.0
CATEGORIES=	databases
MASTER_SITES=	https://github.com/agroal/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High-performance protocol-native connection pool for PostgreSQL
WWW=		https://agroal.github.io/pgagroal/

LICENSE=	BSD3CLAUSE

BROKEN_armv7=	wants long to be a 64 bit type

BUILD_DEPENDS=	rst2man:textproc/py-docutils
LIB_DEPENDS=	libcjson.so:devel/libcjson \
		libev.so:devel/libev

USES=		cmake ssl
USE_LDCONFIG=	yes
USE_RC_SUBR=	pgagroal

SUB_LIST=	PGAGROAL_RUNDIR="${PGAGROAL_RUNDIR}"

USERS=		pgagroal
GROUPS=		pgagroal

PLIST_SUB+=	PGAGROAL_GROUP="${GROUPS}" \
		PGAGROAL_LOGDIR="${PGAGROAL_LOGDIR}" \
		PGAGROAL_RUNDIR="${PGAGROAL_RUNDIR}" \
		PGAGROAL_USER="${USERS}"  \
		PORTVERSION="${DISTVERSION}"

PGAGROAL_GROUP?=	pgagroal
PGAGROAL_USER?=		pgagroal

PGAGROAL_RUNDIR?=	/var/run/pgagroal
PGAGROAL_LOGDIR?=	/var/log/pgagroal

post-patch:
	@${MV} ${WRKSRC}/doc/etc/pgagroal.conf \
		${WRKSRC}/doc/etc/pgagroal.conf.sample
	@${MV} ${WRKSRC}/doc/etc/pgagroal_hba.conf \
		${WRKSRC}/doc/etc/pgagroal_hba.conf.sample

post-install:
	@${MKDIR} ${STAGEDIR}${PGAGROAL_RUNDIR} \
		${STAGEDIR}${PGAGROAL_LOGDIR}

.include <bsd.port.mk>
