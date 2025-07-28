PORTNAME=	pgbouncer
DISTVERSION=	1.24.1
CATEGORIES=	databases
MASTER_SITES=	https://www.pgbouncer.org/downloads/files/${DISTVERSION}/

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	Lightweight connection pooler for PostgreSQL
WWW=		https://www.pgbouncer.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

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

USERS=		${PGBOUNCER_USER}
GROUPS=		${PGBOUNCER_GROUP}

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
	${INSTALL_MAN} ${WRKSRC}/doc/pgbouncer.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/pgbouncer.5 ${STAGEDIR}${PREFIX}/share/man/man5/
	${INSTALL_DATA} ${WRKSRC}/etc/pgbouncer.ini \
		${STAGEDIR}${PREFIX}/etc/pgbouncer.ini.sample
	${INSTALL_DATA} ${WRKSRC}/etc/userlist.txt \
		${STAGEDIR}${PREFIX}/etc/pgbouncer.users.sample
	@${MKDIR} ${STAGEDIR}${PGBOUNCER_RUNDIR} \
		${STAGEDIR}${PGBOUNCER_LOGDIR}

.include <bsd.port.mk>
