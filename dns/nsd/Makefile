# New ports collection makefile for:	nsd
# Date created:				08 August 2002
# Whom:					alexis
#
# $FreeBSD$
#

# To pre-select options in batch mode, run make like this:
#
#  make -DBATCH NSD_OPTIONS="ROOT_SERVER BIND8_STATS"
#
# the options are the same names as in the scripts/configure.nsd file.
# NSD_OPTIONS can be set in /etc/make.conf also.

PORTNAME=	nsd
PORTVERSION=	2.3.0
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/	\
		ftp://ftp.rhnet.is/pub/nsd/

MAINTAINER=	oli@isnic.is
COMMENT=	An authoritative only non-recursive name server

USE_RC_SUBR=	yes

NSDUSER?=	bind
NSDDIR?=	${PREFIX}/etc/nsd
NSDDBFILE?=	/var/db/nsd.database

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-user=${NSDUSER} \
		--with-configdir=${NSDDIR} \
		--with-pidfile=/var/run/nsd.pid \
		--with-dbfile=${NSDDBFILE} \
		--with-libwrap
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

SED_SCRIPT=	-e 's,%%NSDUSER%%,${NSDUSER},g' \
		-e 's,%%NSDDIR%%,${NSDDIR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

MAN8=	nsd.8 zonec.8 nsdc.8 nsd-notify.8 nsd-xfer.8

PORTDOCS=	README RELNOTES CREDITS DIFFERENCES REQUIREMENTS

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		NSD_OPTIONS="${NSD_OPTIONS}"

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.nsd

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.if defined(NOPORTDOCS)
READMEDIR=no
.else
READMEDIR=${PREFIX}/share/doc/nsd
.endif

post-install:
	${SED} ${SED_SCRIPT} < ${FILESDIR}/nsd.sh.tmpl >${WRKDIR}/nsd.sh
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/nsd.zones.sample \
		${PREFIX}/etc/nsd/nsd.zones.sample
	${INSTALL_SCRIPT} ${WRKDIR}/nsd.sh ${PREFIX}/etc/rc.d/
	@${CAT} ${PKGMESSAGE}

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
