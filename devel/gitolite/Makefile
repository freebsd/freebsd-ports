# New ports collection makefile for:	gitolite
# Date created:				07-28-2011
# Whom:					milki <milki@rescomp.berkeley.edu>
#
# $FreeBSD$
#

PORTNAME=	gitolite
PORTVERSION=	2.3
CATEGORIES=	devel
MASTER_SITES=	http://milki.github.com/${PORTNAME}/ \
		LOCAL/tdb

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	An access control layer on top of git

LICENSE=	GPLv2

RUN_DEPENDS=	git>=0:${PORTSDIR}/devel/git

USE_PERL5=	yes

SUB_FILES=	pkg-message

OPTIONS=	GITUSER	"Create git user as gitolite provider" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GITUSER)
USERS=		git
GROUPS=		${USERS}
PLIST_SUB+=	GITUSER=""
.else
PLIST_SUB+=	GITUSER="@comment "
.endif

GLAUTHCOMMAND=	\
\#!/bin/sh\n \
exec ${PREFIX}/libexec/gitolite/gl-auth-command \"\$$@\"\n

GLSETUP=	\
\#!/bin/sh\n \
exec ${PREFIX}/libexec/gitolite/gl-setup \"\$$@\"\n

post-patch:
	@${ECHO} -e "${GLAUTHCOMMAND}" > ${WRKDIR}/auth-command
	@${ECHO} -e "${GLSETUP}" > ${WRKDIR}/setup
.for FILE in gl-admin-push gl-auth-command gl-compile-conf gl-conf-convert gl-mirror-push gl-mirror-shell gl-query-rc gl-setup gl-setup-authkeys gl-time gl-tool sshkeys-lint
	@${REINPLACE_CMD} \
		-Ee '1s|#!/usr/bin/perl|#!${PERL}|' \
		${WRKSRC}/src/${FILE}
.endfor
	@${REINPLACE_CMD} \
		-Ee '1s|#!/usr/bin/perl|#!${PERL}|' \
		${WRKSRC}/hooks/common/update

do-build:
	-@${RM} ${WRKSRC}/src/gl-system-install
	@${REINPLACE_CMD} \
		-E 's%^GL_PACKAGE_CONF=.*%GL_PACKAGE_CONF=${DATADIR}/conf;%' \
		${WRKSRC}/src/gl-setup
	@${REINPLACE_CMD} \
		-E "s%^#[[:blank:]]*\\\$$GL_PACKAGE_CONF[[:blank:]]*=.*%\$$GL_PACKAGE_CONF = '${DATADIR}/conf';%" \
		${WRKSRC}/conf/example.gitolite.rc
	@${REINPLACE_CMD} \
		-E "s%^#[[:blank:]]*\\\$$GL_PACKAGE_HOOKS[[:blank:]]*=.*%\$$GL_PACKAGE_HOOKS = '${DATADIR}/hooks';%" \
		${WRKSRC}/conf/example.gitolite.rc

post-build:
	@${FIND} ${WRKSRC} -name "*.bak" -delete
	@${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	${MKDIR} ${PREFIX}/libexec/gitolite
	${INSTALL_SCRIPT} ${WRKSRC}/src/* ${PREFIX}/libexec/gitolite/
	${MKDIR} ${DATADIR}/conf
	${INSTALL_DATA} ${WRKSRC}/conf/* ${DATADIR}/conf
	${MKDIR} ${DATADIR}/hooks
	(cd ${WRKSRC}/hooks && ${COPYTREE_BIN} \* ${DATADIR}/hooks)
	${INSTALL_SCRIPT} ${WRKDIR}/auth-command ${PREFIX}/bin/gl-auth-command
	${INSTALL_SCRIPT} ${WRKDIR}/setup ${PREFIX}/bin/gl-setup

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
