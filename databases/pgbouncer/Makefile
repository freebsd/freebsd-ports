PORTNAME=	pgbouncer
PORTVERSION=	1.17.0
CATEGORIES=	databases
MASTER_SITES=	https://pgbouncer.github.io/downloads/files/${PORTVERSION}/ \
		http://pgbouncer.github.io/downloads/files/${PORTVERSION}/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Lightweight connection pooler for PostgreSQL

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		cpe gmake pkgconfig ssl
USE_RC_SUBR=	pgbouncer

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-evdns \
		--with-libevent=${LOCALBASE}
CONFIGURE_ENV+=	PTHREAD_LIBS="-lpthread"

PORTSCOUT=	site:https://pgbouncer.github.io/downloads/
SUB_FILES=	pkg-message
SUB_LIST+=	PGBOUNCER_RUNDIR="${PGBOUNCER_RUNDIR}"

USERS=		pgbouncer
GROUPS=		pgbouncer

PLIST_SUB+=	PGBOUNCER_GROUP="${GROUPS}" \
		PGBOUNCER_LOGDIR="${PGBOUNCER_LOGDIR}" \
		PGBOUNCER_RUNDIR="${PGBOUNCER_RUNDIR}" \
		PGBOUNCER_USER="${USERS}"

OPTIONS_DEFINE=	CARES

CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
CARES_CONFIGURE_WITH=	cares

PGBOUNCER_GROUP?=	pgbouncer
PGBOUNCER_USER?=	pgbouncer

PGBOUNCER_RUNDIR?=	/var/run/pgbouncer
PGBOUNCER_LOGDIR?=	/var/log/pgbouncer

post-patch:
	@${REINPLACE_CMD} -e "s|= /etc/pgbouncer/userlist.txt|= ${PREFIX}/etc/pgbouncer.users|g" \
		-e "s|= /var/log/pgbouncer/pgbouncer.log|= ${PGBOUNCER_LOGDIR}/pgbouncer.log|g" \
		-e "s|= /var/run/pgbouncer/pgbouncer.pid|= ${PGBOUNCER_RUNDIR}/pgbouncer.pid|g" \
		-e "s|= /etc/pgbouncer/resolv.conf|= ${PREFIX}/etc/pgbouncer-resolv.conf|g" \
		-e "s|include /etc/pgbouncer/pgbouncer-other.ini|include ${PREFIX}/etc/pgbouncer-other.ini|g" \
		${WRKSRC}/etc/pgbouncer.ini

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgbouncer ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/pgbouncer.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/pgbouncer.5 ${STAGEDIR}${PREFIX}/man/man5/
	${INSTALL_DATA} ${WRKSRC}/etc/pgbouncer.ini \
		${STAGEDIR}${PREFIX}/etc/pgbouncer.ini.sample
	${INSTALL_DATA} ${WRKSRC}/etc/userlist.txt \
		${STAGEDIR}${PREFIX}/etc/pgbouncer.users.sample
	@${MKDIR} ${STAGEDIR}${PGBOUNCER_RUNDIR} \
		${STAGEDIR}${PGBOUNCER_LOGDIR}

.include <bsd.port.mk>
