# New ports collection makefile for:	msql2
# Date created:		December 17th 1996
# Whom:			jfitz
#
# $FreeBSD$
#

PORTNAME=	msql
PORTVERSION=	2.0.4.1
CATEGORIES=	databases

MAINTAINER=	jfitz@FreeBSD.org

# Not free for commercial use.  Must create a user on the local system
NO_PACKAGE=	YES
RESTRICTED=	"restrictive copyright (no commercial use)"

MAKE_ENV+=	WRKSRC=${WRKSRC}

# Uncomment this if you're upgrading from <= b4 to >= b5 and have already
# dumped your databases (or just build with -DOVERWRITE_DB)
#OVERWRITE_DB=	YES

do-configure:
		cd ${WRKSRC}; make target
		cd ${WRKSRC}/targets/freebsd; ${SETENV} ${MAKE_ENV} ./setup
		@${SETENV} ${MAKE_ENV} /usr/bin/perl ${SCRIPTDIR}/customize_scripts

pre-install:
		@${SETENV} ${MAKE_ENV} /usr/bin/perl ${SCRIPTDIR}/check_old_version
		@${SETENV} ${MAKE_ENV} /usr/bin/perl ${SCRIPTDIR}/createuser

post-install:
		@${INSTALL_SCRIPT} ${WRKSRC}/scripts/run_daemon ${PREFIX}/bin
		@${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/share/doc/msql
		@for file in msql2d msqladmin msqlimport msqlexport; do\
			/usr/bin/chgrp msql ${PREFIX}/bin/$$file; \
		done
		@for file in RELEASE_NOTES MSQL_BOOK INSTALL; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/doc/msql; \
		done
		@${CHMOD} 751 ${PREFIX}/etc/msql2/
		@${CHOWN} -R msql.msql ${PREFIX}/etc/msql2/
		@${MKDIR} ${PREFIX}/etc/rc.d
		@if [ ! -f ${PREFIX}/etc/rc.d/msql2.sh ]; then \
			${ECHO} "Installing ${PREFIX}/etc/rc.d/msql2.sh startup file."; \
			${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/msql2.sh; \
			${ECHO} "[ -x ${PREFIX}/bin/msql2d ] && su -l msql -c 'exec ${PREFIX}/bin/msql2d' > /dev/null 2>&1 & && ${ECHO} -n ' msql2'" >> ${PREFIX}/etc/rc.d/msql2.sh; \
			${CHMOD} 751 ${PREFIX}/etc/rc.d/msql2.sh; \
		fi
.if !defined(BATCH)
		@ /usr/bin/more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE="- You must manually obtain ${DISTFILES} from 'http://www.Hughes.com.au' and place it in ${DISTDIR}.  The distribution requires registration prior to use"
.endif

.include <bsd.port.post.mk>
