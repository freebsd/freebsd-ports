# Ports collection makefile for:  pgbouncer
# Date created:			  19 July 2007
# Whom:				  Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	pgbouncer
PORTVERSION=	1.3.1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2284/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Lightweight connection pooler for PostgreSQL

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

USE_RC_SUBR=	pgbouncer.sh
SUB_FILES=	pkg-message pkg-install pkg-deinstall

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if ! defined(NO_INSTALL_MANPAGES)
MAN1=		pgbouncer.1
MAN5=		pgbouncer.5
.endif

CONFIGURE_ARGS=	--with-libevent=${LOCALBASE}

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message

PGBOUNCER_USER?=	pgbouncer
PGBOUNCER_GROUP?=	pgbouncer

PGBOUNCER_RUNDIR?=	/var/run/pgbouncer
PGBOUNCER_LOGDIR?=	/var/log/pgbouncer

.include <bsd.port.pre.mk>
# Parse ${PORTSDIR}/UIDs and GIDs for the defaults
USER!=	${GREP} -E '^${PGBOUNCER_USER}:' ${PORTSDIR}/UIDs | \
		${SED} -Ee 's/^([^:]*):([^:]*):([^:]*):([^:]*)::0:0:([^:]*):([^:]*):([^:]*)$$/USER="\1" UID="\3" GECOS="\5" HOME="\6" SHELL="\7"/'
GROUP!=	${GREP} -E '^${PGBOUNCER_GROUP}:' ${PORTSDIR}/GIDs | \
		${SED} -Ee 's/^([^:]*):([^:]*):([^:]*):$$/GROUP="\1" GID="\3"/'

# Apply the defaults where necessary
PGBOUNCER_USER?=	${USER:MUSER*:C/^[^=]*=\"([^\"]*)\"$/\1/}
PGBOUNCER_UID?=		${USER:MUID*:C/^[^=]*=\"([^\"]*)\"$/\1/}
PGBOUNCER_GECOS?=	${USER:MGECOS*:C/^[^=]*=\"([^\"]*)\"$/\1/}
PGBOUNCER_HOME?=	${USER:MHOME*:C/^[^=]*=\"([^\"]*)\"$/\1/}
PGBOUNCER_SHELL?=	${USER:MSHELL*:C/^[^=]*=\"([^\"]*)\"$/\1/}
PGBOUNCER_GROUP?=	${GROUP:MGROUP*:C/^[^=]*=\"([^\"]*)\"$/\1/}
PGBOUNCER_GID?=		${GROUP:MGID*:C/^[^=]*=\"([^\"]*)\"$/\1/}

SUB_LIST+=	PGBOUNCER_USER="${PGBOUNCER_USER}" \
		PGBOUNCER_UID="${PGBOUNCER_UID}" \
		PGBOUNCER_GECOS="${PGBOUNCER_GECOS}" \
		PGBOUNCER_HOME="${PGBOUNCER_HOME}" \
		PGBOUNCER_SHELL="${PGBOUNCER_SHELL}" \
		PGBOUNCER_GROUP="${PGBOUNCER_GROUP}" \
		PGBOUNCER_GID="${PGBOUNCER_GID}" \
		PGBOUNCER_LOGDIR="${PGBOUNCER_LOGDIR}" \
		PGBOUNCER_RUNDIR="${PGBOUNCER_RUNDIR}" \
		CHMOD="${CHMOD}" CHOWN="${CHOWN}" MKDIR="${MKDIR}" PW="${PW}"

post-patch:
	@${REINPLACE_CMD} -e "s|= pgbouncer.log|= ${PGBOUNCER_LOGDIR}/pgbouncer.log|g" \
		-e "s|= pgbouncer.pid|= ${PGBOUNCER_RUNDIR}/pgbouncer.pid|g" \
		${WRKSRC}/etc/pgbouncer.ini

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
