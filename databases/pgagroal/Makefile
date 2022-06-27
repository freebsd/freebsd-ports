PORTNAME=	pgagroal
PORTVERSION=	1.4.2
CATEGORIES=	databases
MASTER_SITES=	https://github.com/agroal/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High-performance protocol-native connection pool for PostgreSQL

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils
LIB_DEPENDS=	libev.so:devel/libev

USES=		cmake pathfix ssl
USE_LDCONFIG=	yes
USE_RC_SUBR=	pgagroal

SUB_LIST=	PGAGROAL_RUNDIR="${PGAGROAL_RUNDIR}"

USERS=		pgagroal
GROUPS=		pgagroal

PLIST_SUB+=	PGAGROAL_GROUP="${GROUPS}" \
		PGAGROAL_LOGDIR="${PGAGROAL_LOGDIR}" \
		PGAGROAL_RUNDIR="${PGAGROAL_RUNDIR}" \
		PGAGROAL_USER="${USERS}"

PGAGROAL_GROUP?=	pgagroal
PGAGROAL_USER?=		pgagroal

PGAGROAL_RUNDIR?=	/var/run/pgagroal
PGAGROAL_LOGDIR?=	/var/log/pgagroal

post-patch:
	@${MV} ${WRKSRC}/doc/etc/pgagroal.conf \
		${WRKSRC}/doc/etc/pgagroal.conf.sample
	@${MV} ${WRKSRC}/doc/etc/pgagroal_hba.conf \
		${WRKSRC}/doc/etc/pgagroal_hba.conf.sample
	@${REINPLACE_CMD} 's|etc/pgagroal.conf|etc/pgagroal.conf.sample|g; \
		s|etc/pgagroal_hba.conf|etc/pgagroal_hba.conf.sample|g' \
		${WRKSRC}/doc/CMakeLists.txt
	@${REINPLACE_CMD} 's|pgagraol.%d.pid|pgagroal.pid|g' \
		${WRKSRC}/src/libpgagroal/configuration.c

post-install:
	@${MKDIR} ${STAGEDIR}${PGAGROAL_RUNDIR} \
		${STAGEDIR}${PGAGROAL_LOGDIR}

.include <bsd.port.mk>
