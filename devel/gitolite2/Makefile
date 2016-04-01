# $FreeBSD$

PORTNAME=	gitolite
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GH \
		LOCAL/milki \
		LOCAL/tdb
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Access control layer on top of git

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

RUN_DEPENDS=	git>=0:devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	sitaramc
GH_TAGNAME=	912a8bd

CONFLICTS=	gitolite-[^2]*

USES=		cpe perl5 shebangfix
CPE_VENDOR=	sitaram_chamarty
SHEBANG_FILES=	hooks/common/update \
		src/gl-admin-push \
		src/gl-auth-command \
		src/gl-compile-conf \
		src/gl-conf-convert \
		src/gl-dryrun \
		src/gl-install \
		src/gl-mirror-push \
		src/gl-mirror-shell \
		src/gl-query-rc \
		src/gl-setup \
		src/gl-setup-authkeys \
		src/gl-time \
		src/gl-tool \
		src/sshkeys-lint
NO_ARCH=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GITUSER
OPTIONS_SUB=	yes

GITUSER_DESC=	Create git user as gitolite provider
GITUSER_VARS=	USERS=git GROUPS=git

GLAUTHCOMMAND=	\
\#!/bin/sh\n \
exec ${PREFIX}/libexec/gitolite/gl-auth-command \"\$$@\"\n

GLSETUP=	\
\#!/bin/sh\n \
exec ${PREFIX}/libexec/gitolite/gl-setup \"\$$@\"\n

post-patch:
	@${ECHO} -e "${GLAUTHCOMMAND}" > ${WRKDIR}/auth-command
	@${ECHO} -e "${GLSETUP}" > ${WRKDIR}/setup

do-build:
	echo "v${PORTVERSION}-0-g${GH_TAGNAME}" > ${WRKSRC}/conf/VERSION
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
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gitolite
	${INSTALL_SCRIPT} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/libexec/gitolite/
	@${MKDIR} ${STAGEDIR}${DATADIR}/conf
	${INSTALL_DATA} ${WRKSRC}/conf/* ${STAGEDIR}${DATADIR}/conf
	@${MKDIR} ${STAGEDIR}${DATADIR}/hooks
	(cd ${WRKSRC}/hooks && ${COPYTREE_BIN} \* ${STAGEDIR}${DATADIR}/hooks)
	${INSTALL_SCRIPT} ${WRKDIR}/auth-command ${STAGEDIR}${PREFIX}/bin/gl-auth-command
	${INSTALL_SCRIPT} ${WRKDIR}/setup ${STAGEDIR}${PREFIX}/bin/gl-setup

.include <bsd.port.mk>
