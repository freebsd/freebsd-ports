# Created by: jfitz
# $FreeBSD$

PORTNAME=	msql
PORTVERSION=	2.0.12
PORTREVISION=	4
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Mini SQL server, version 2

CONFLICTS=	msql-3* msql3-*

USES=		perl5
USE_LDCONFIG=	YES
PKGMESSAGE=	${FILESDIR}/post-install-notes

USERS=		${PORTNAME}
GROUPS=		${USERS}

# Not free for commercial use.
RESTRICTED=	restrictive copyright (no commercial use)
MANUAL_PACKAGE_BUILD=	distfile unavailable on pointyhat

CFLAGS+=	-DANSI_ARGS
MAKE_ENV+=	WRKSRC=${WRKSRC}

# Uncomment this if you're upgrading from <= b4 to >= b5 and have already
# dumped your databases (or just build with -DOVERWRITE_DB)
#OVERWRITE_DB=	YES

NO_STAGE=	yes
post-patch:
		cd ${FILESDIR}; \
		cp slibinstall.mm slibrary_unix.mm ${WRKSRC}/src/makegen
		@${REINPLACE_CMD} -e "s|'bison -y' byacc|byacc 'bison -y'|g" \
			${WRKSRC}/src/conf/configure

do-configure:
		cd ${WRKSRC}; ${MAKE} target
		cd ${WRKSRC}/targets/freebsd; ${SETENV} ${MAKE_ENV} ./setup
		@${SETENV} ${MAKE_ENV} ${PERL} ${SCRIPTDIR}/customize_scripts

pre-install:
		@${SETENV} ${MAKE_ENV} ${PERL} ${SCRIPTDIR}/check_old_version

post-install:
		@${INSTALL_SCRIPT} ${WRKSRC}/scripts/run_daemon ${PREFIX}/bin
		@${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/share/doc/msql
		@for file in msqladmin msqlimport msqlexport; do\
			${CHGRP} msql ${PREFIX}/bin/$$file; \
		done
		${CHGRP} msql ${PREFIX}/sbin/msql2d
		@for file in RELEASE_NOTES MSQL_BOOK INSTALL; do \
			${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/doc/msql; \
		done
		@${CHMOD} 751 ${PREFIX}/etc/msql2/
		@${CHOWN} -R msql:msql ${PREFIX}/etc/msql2/
		@${MKDIR} ${PREFIX}/etc/rc.d
		@if [ ! -f ${PREFIX}/etc/rc.d/msql2.sh ]; then \
			${ECHO_MSG} "Installing ${PREFIX}/etc/rc.d/msql2.sh startup file."; \
			${INSTALL_SCRIPT} -m 751 ${FILESDIR}/msql2.sh \
				${PREFIX}/etc/rc.d/msql2.sh; \
		fi
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900000
BROKEN=	Broken on FreeBSD 9+
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
DISTFILE_INSTRUCTIONS=	\n\
- You must manually obtain ${DISTFILES} from \n\
http://www.Hughes.com.au/download/\n\
and place it in ${DISTDIR}.\n\
The distribution requires registration prior to use.\n\n
.endif

.if defined(DISTFILE_INSTRUCTIONS)
.if defined(PACKAGE_BUILDING)
IGNORE=		requires manual fetch
.else
pre-fetch:
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif
.endif

.include <bsd.port.post.mk>
