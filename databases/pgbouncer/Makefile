# Ports collection makefile for:  pgbouncer
# Date created:			  19 July 2007
# Whom:				  Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	pgbouncer
PORTVERSION=	1.5.2
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3293/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Lightweight connection pooler for PostgreSQL

LICENSE=	BSD

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

PORTSCOUT=	site:http://pgfoundry.org/frs/?group_id=1000258

USERS=		pgbouncer
GROUPS=		pgbouncer

USE_RC_SUBR=	pgbouncer
SUB_FILES=	pkg-message pkg-install pkg-deinstall

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if ! defined(NO_INSTALL_MANPAGES)
MAN1=		pgbouncer.1
MAN5=		pgbouncer.5
.endif

CONFIGURE_ARGS=	--with-libevent=${LOCALBASE}
CONFIGURE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LIBS=${PTHREAD_LIBS}

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message

PGBOUNCER_USER?=	pgbouncer
PGBOUNCER_GROUP?=	pgbouncer

PGBOUNCER_RUNDIR?=	/var/run/pgbouncer
PGBOUNCER_LOGDIR?=	/var/log/pgbouncer

BUILD_DEPENDS+=		${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed

.include <bsd.port.pre.mk>

SUB_LIST+=	PGBOUNCER_USER="${USERS}" \
		PGBOUNCER_GROUP="${GROUPS}" \
		PGBOUNCER_LOGDIR="${PGBOUNCER_LOGDIR}" \
		PGBOUNCER_RUNDIR="${PGBOUNCER_RUNDIR}" \
		CHMOD="${CHMOD}" CHOWN="${CHOWN}" MKDIR="${MKDIR}" PW="${PW}"

post-patch:
	@${REINPLACE_CMD} -e "s|= pgbouncer.log|= ${PGBOUNCER_LOGDIR}/pgbouncer.log|g" \
		-e "s|= pgbouncer.pid|= ${PGBOUNCER_RUNDIR}/pgbouncer.pid|g" \
		${WRKSRC}/etc/pgbouncer.ini
	@${REINPLACE_CMD} -e "s|sed -n|${LOCALBASE}/bin/gsed -n|g" \
		${WRKSRC}/lib/find_modules.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgbouncer ${PREFIX}/bin/
.if ! defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/doc/pgbouncer.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/pgbouncer.5 ${PREFIX}/man/man5/
.endif
	${INSTALL_DATA} ${WRKSRC}/etc/pgbouncer.ini ${PREFIX}/etc/pgbouncer.ini.sample
	${INSTALL_DATA} ${WRKSRC}/etc/userlist.txt ${PREFIX}/etc/pgbouncer.users.sample

post-install:
	@if [ ! -f ${PREFIX}/etc/pgbouncer.ini ]; then \
		${CP} -p ${PREFIX}/etc/pgbouncer.ini.sample ${PREFIX}/etc/pgbouncer.ini ; \
	fi
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
