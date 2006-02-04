# New ports collection makefile for:	xgate
# Date created:				2005/10/22
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	xgate
PORTVERSION=	3.5pl3
CATEGORIES=	japanese mail www java
MASTER_SITES=	http://www.orangesoft.co.jp/xGate/download/
DISTNAME=	${PORTNAME}pkg${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	xGate

MAINTAINER=	nork@FreeBSD.org
COMMENT=	xGate webmail system implemented by Servlet over IMAP4/POP3

RUN_DEPENDS=	tomcat41ctl:${PORTSDIR}/www/jakarta-tomcat41 \
		${JAVA_HOME}/jre/lib/security/.jce_policy14:${PORTSDIR}/security/jce_policy14

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

PLIST_SUB=	T=${APP_HOME:S|^${LOCALBASE}/||} \
		WWWUID=${WWWUID} WWWGID=${WWWGID}

PORTDOCS=	AdminGuide_V3.5.pdf		\
		BasicPkgInstallGuide_V3.5.pdf	\
		ConfigSetupGuide_V3.5.pdf	\
		LDAPSchema_V3.2.xls		\
		PCUserGuide_V3.5.pdf		\
		ReleaseNote_V3.5.pdf		\
		ReleaseNote_V3.5PL1.pdf		\
		ReleaseNote_V3.5PL2.pdf		\
		ReleaseNote_V3.5PL3.pdf		\
		UserGuide_V3.5.pdf		\
		xGate32to35migration.pdf

RESTRICTED=	"Commercial license"
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

.include <bsd.port.pre.mk>

APP_HOME!=	${MAKE} -C ${PORTSDIR}/www/jakarta-tomcat41 -VAPP_HOME
WWWOWN?=	www
WWWGRP?=	www

CNFLSTS=	account/admin.ndt	\
		account/license.dat	\
		conf/access.dat		\
		conf/address.data	\
		conf/address.map	\
		conf/admin.ldif		\
		conf/admin_group.ldif	\
		conf/createuser.conf	\
		conf/device_match.conf	\
		conf/entry.data		\
		conf/extra.types	\
		conf/group.data		\
		conf/group.map		\
		conf/ldap.map		\
		conf/log.conf		\
		conf/notify.conf	\
		conf/terminal.dat	\
		conf/user.data		\
		conf/xgate.conf

post-extract:
	@${MKDIR} ${WRKSRC}/xgate
	@cd ${WRKSRC}/xgate && ${JAR} xf ../xgate.war
.for conf in ${CNFLSTS}
	@cd ${WRKSRC}/xgate/WEB-INF && ${MV} ${conf} ${conf}-dist
.endfor

post-patch:
	${FIND} ${WRKSRC} -name \*.orig -print0 | ${XARGS} -0 ${RM}

do-install:
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} /var/log/xgate
	@cd ${WRKSRC} && ${FIND} xgate | \
		${CPIO} -pdm -L -R ${WWWOWN}:${WWWGRP} ${APP_HOME}/webapps/
.for conf in ${CNFLSTS}
	@cd ${APP_HOME}/webapps/xgate/WEB-INF && \
		[ ! -f ${conf} ] && ${CP} -p ${conf}-dist ${conf} || ${TRUE}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docf in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/docs/${docf} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
