# New ports collection makefile for:	QuakeForge
# Date created:		4 January 2000
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	QuakeForge
PORTVERSION=	0.10.0p
CATEGORIES=	games
# ${MASTER_SITES} is only for if CVS won't work, period.
MASTER_SITES=	http://www.gsoft.com.au/~doconnor/
DISTNAME=	quakeforge

MAINTAINER=	darius@dons.net.au

.if defined(USE_GLX)
LIB_DEPENDS=	GL.1:${PORTSDIR}/graphics/glx
.else
CONFIGURE_ARGS+= --without-opengl
.endif

.include <bsd.port.pre.mk>
CAT?=		/bin/cat
DISTFILES!=	${CAT} ${FILESDIR}/distfiles

CVS_CMD?=	cvs -z3
CVS_DATE=	Tue Jan 4 03:20:17 GMT 2000
SED?=		/usr/bin/sed
CVS_DATE_!=	${ECHO} -n "${CVS_DATE}" | ${SED} 's/[ \t:]/_/g'
CVS_SITES=	:pserver:anonymous@cvs.quake.sourceforge.net:/cvsroot/quake
DIRNAME=	${PORTNAME}-0.10.0pre
STAMPFILE=	${DISTDIR}/${DIRNAME}/.stamp
WRKSRC=		${WRKDIR}/quakeforge
USE_GMAKE=	yes
USE_AUTOCONF=	yes
USE_XLIB=	yes
PLIST=		${WRKDIR}/PLIST

pre-fetch:
.if !defined(USE_GLX)
	@${ECHO_MSG} "Define USE_GLX to use GLX (otherwise it is explicitly disabled!)"
.endif

.if defined(BATCH)
do-fetch: fetchsrctarball
.else
do-fetch:
	@if [ ! -e ${STAMPFILE} ] || \
	    [ "X${CVS_DATE}" != "X$$(${CAT} ${STAMPFILE})" ]; then \
		${ECHO_MSG} "No stamp file (or out of date)"; \
		if [ -e ${DISTDIR}/${DIRNAME}.${CVS_DATE_}.tar.gz ]; then \
			cd ${DISTDIR}; \
			${TAR} xfz ${DIRNAME}.${CVS_DATE_}.tar.gz \
			    ${DISTFILES}; \
			${ECHO} -n "${CVS_DATE}" > ${STAMPFILE}; \
			exit; \
		fi; \
		unset CVS_RSH CVS_SERVER CVS_LOGIN || ${TRUE}; \
		if [ -n "${PORTS_CVS_RSH}" ]; then \
			export CVS_RSH="${PORTS_CVS_RSH}"; \
		fi; \
		${MKDIR} ${DISTDIR}/${DIRNAME} && \
		cd ${DISTDIR}/${DIRNAME}; \
		for CVS_SITE in ${CVS_SITES}; do \
			${ECHO_MSG} ">> Attempting to CVS checkout from $${CVS_SITE}."; \
			case "$${CVS_SITE}" in \
			:pserver:*) \
				CVS_LOGIN=yes; \
				;; \
			*) \
				CVS_LOGIN=no; \
				;; \
			esac; \
			if [ "X$${CVS_LOGIN}" = "Xyes" ]; then \
				${ECHO_MSG} ">>** Please hit enter here for the password."; \
				${CVS_CMD} -d $${CVS_SITE} login < /dev/null; \
			fi; \
			if ${CVS_CMD} -d $${CVS_SITE} co -D "${CVS_DATE}" \
			    ${DISTNAME}; then \
				if [ "X$${CVS_LOGIN}" = "Xyes" ]; then \
					${CVS_CMD} -d $${CVS_SITE} logout < /dev/null; \
				fi; \
				${ECHO} -n ${CVS_DATE} > ${STAMPFILE}; \
				exit; \
			fi; \
			if [ "X$${CVS_LOGIN}" = "Xyes" ]; then \
				${CVS_CMD} -d $${CVS_SITE} logout < /dev/null; \
			fi; \
		done; \
		${ECHO_MSG} ">> Couldn't CVS checkout ${DIRNAME}.  Please try to retrieve"; \
		${ECHO_MSG} ">> a snapshot with \"make fetchsrctarball\" and try again."; \
		exit 1; \
	fi
.endif

makesrctarball: fetch
	@cd ${DISTDIR}; \
	${ECHO_MSG} ">> Creating source tarball in ${DISTDIR}"; \
	${ECHO_MSG} ">> \"${DIRNAME}.${CVS_DATE_}.tar.gz\"."; \
	${TAR} cfz ${DIRNAME}.${CVS_DATE_}.tar.gz ${DIRNAME}

fetchsrctarball:
	@cd ${DISTDIR}; \
	file=${DIRNAME}.${CVS_DATE_}.tar.gz; \
	if [ -e $$file ]; then \
		exit; \
	fi; \
	${ECHO_MSG} ">> $$file doesn't seem to exist on this system."; \
	for site in ${MASTER_SITES}; do \
		${ECHO_MSG} ">> Attempting to fetch from $${site}."; \
		if ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} \
		    $${site}$${file}; then \
			exit; \
		fi; \
	done; \
	${ECHO_MSG} ">> Couldn't fetch $$file."; \
	${ECHO_MSG} ">> Please try to retrieve this file manually into"; \
	${ECHO_MSG" ">> ${_DISTDIR} and try again."; \
	exit 1 ;

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -r ${DISTDIR}/${DIRNAME}/${DISTNAME} ${WRKDIR}

pre-configure:
	@${CP} ${PKGDIR}/PLIST ${PLIST}
.if defined(USE_GLX)
	${CAT} ${PKGDIR}/PLIST.glx >>${PLIST}
.endif
	cd ${WRKSRC}; \
	autoheader;

BINARIES=	quake-x11 qw-client-x11 qw-server
.if defined(USE_GLX)
BINARIES+=	quake-gl qw-client-gl
.endif

do-install:
.for binary in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/targets/${binary} ${PREFIX}/bin/
.endfor

.include <bsd.port.post.mk>
