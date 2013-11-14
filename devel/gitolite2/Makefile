# $FreeBSD$

PORTNAME=	gitolite
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GH \
		LOCAL/tdb
PKGNAMESUFFIX=	2
DISTNAME=	g-${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-${GH_COMMIT}

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	An access control layer on top of git

LICENSE=	GPLv2

RUN_DEPENDS=	git>=0:${PORTSDIR}/devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	sitaramc
GH_COMMIT=	912a8bd
GH_TAGNAME=	${GH_COMMIT}

CONFLICTS=	gitolite-[^2]*

USES=		perl5

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GITUSER

GITUSER_DESC=	Create git user as gitolite provider

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGITUSER}
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
	echo "v${PORTVERSION}-0-g${GH_COMMIT}" > ${WRKSRC}/conf/VERSION
	-@${RM} ${WRKSRC}/src/gl-system-install
	@${REINPLACE_CMD} \
		-E 's%^GL_PACKAGE_CONF=.*%GL_PACKAGE_CONF=${DATADIR}/conf;%' \
		${WRKSRC}/src/gl-setup
	@${REINPLACE_CMD} \
		-E "s%^[[:blank:]]*\\\$$GL_PACKAGE_CONF[[:blank:]]*=.*%\$$GL_PACKAGE_CONF = '${DATADIR}/conf';%" \
		${WRKSRC}/conf/example.gitolite.rc
	@${REINPLACE_CMD} \
		-E "s%^[[:blank:]]*\\\$$GL_PACKAGE_HOOKS[[:blank:]]*=.*%\$$GL_PACKAGE_HOOKS = '${DATADIR}/hooks';%" \
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

.include <bsd.port.mk>
