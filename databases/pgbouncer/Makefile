# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	pgbouncer
PORTVERSION=	1.14.0
CATEGORIES=	databases
MASTER_SITES=	https://pgbouncer.github.io/downloads/files/${PORTVERSION}/ \
		http://pgbouncer.github.io/downloads/files/${PORTVERSION}/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Lightweight connection pooler for PostgreSQL

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent
BUILD_DEPENDS+=	${LOCALBASE}/bin/gsed:textproc/gsed

USES=		gmake ssl pkgconfig

PORTSCOUT=	site:https://pgbouncer.github.io/downloads/

USERS=		pgbouncer
GROUPS=		pgbouncer

USE_RC_SUBR=	pgbouncer
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	CARES
CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
CARES_CONFIGURE_WITH=	cares

CONFIGURE_ARGS=	--with-libevent=${LOCALBASE} --enable-evdns
CONFIGURE_ENV+=	PTHREAD_LIBS="-lpthread"

PGBOUNCER_USER?=	pgbouncer
PGBOUNCER_GROUP?=	pgbouncer

PGBOUNCER_RUNDIR?=	/var/run/pgbouncer
PGBOUNCER_LOGDIR?=	/var/log/pgbouncer

PLIST_SUB+=	PGBOUNCER_USER="${USERS}" \
		PGBOUNCER_GROUP="${GROUPS}" \
		PGBOUNCER_LOGDIR="${PGBOUNCER_LOGDIR}" \
		PGBOUNCER_RUNDIR="${PGBOUNCER_RUNDIR}"
SUB_LIST+=	PGBOUNCER_RUNDIR="${PGBOUNCER_RUNDIR}"

post-patch:
	@${REINPLACE_CMD} -e "s|= pgbouncer.log|= ${PGBOUNCER_LOGDIR}/pgbouncer.log|g" \
		-e "s|= pgbouncer.pid|= ${PGBOUNCER_RUNDIR}/pgbouncer.pid|g" \
		${WRKSRC}/etc/pgbouncer.ini
	@${REINPLACE_CMD} -e "s|sed -n|${LOCALBASE}/bin/gsed -n|g" \
		${WRKSRC}/lib/find_modules.sh

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
