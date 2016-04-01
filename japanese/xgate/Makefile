# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	xgate
PORTVERSION=	3.7pl6
PORTREVISION=	1
CATEGORIES=	japanese mail www java
MASTER_SITES=	http://www.orangesoft.co.jp/index.php/download_file/-/192/
DISTNAME=	${PORTNAME}pkg${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webmail system xGate implemented by Servlet over IMAP4/POP3

RUN_DEPENDS=	${APP_HOME}/bin/bootstrap.jar:www/tomcat6

USES=		dos2unix tar:tgz
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
SHAREOWN=	www
SHAREGRP=	www

PLIST_SUB=	T=${APP_HOME:S|^${LOCALBASE}/||} \
		WWWUID=${WWWOWN} WWWGID=${WWWGRP}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AdminGuide.pdf \
		BasicPkgInstallGuide.pdf \
		ConfigSetupGuide.pdf \
		LDAPSchema_V35_37.xls \
		PCUserGuide.pdf \
		ReleaseNote_V3.5.2.pdf \
		ReleaseNote_V3.5.2PL1.pdf \
		ReleaseNote_V3.5.2PL2.pdf \
		ReleaseNote_V3.5.2PL3_3.7.pdf \
		ReleaseNote_V3.5.2PL4_3.7PL1.pdf \
		ReleaseNote_V3.5.2PL5_3.7PL2.pdf \
		ReleaseNote_V3.5.2PL6_3.7PL3.pdf \
		ReleaseNote_V3.5.2PL7_3.7PL4.pdf \
		ReleaseNote_V3.5.2PL8_3.7PL5.pdf \
		ReleaseNote_V3.5.2PL9_3.7PL6.pdf \
		UserGuide.pdf

RESTRICTED=	Commercial license

.include <bsd.port.options.mk>

APP_HOME!=	${MAKE} -C ${PORTSDIR}/www/tomcat6 -VAPP_HOME

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
		conf/terminal.dat	\
		conf/user.data		\
		conf/xgate.conf

post-extract:
	@${MKDIR} ${WRKSRC}/xgate
	@${TAR} -xvf ${WRKSRC}/xgate.war -C ${WRKSRC}/xgate

post-patch:
.for conf in ${CNFLSTS}
	@cd ${WRKSRC}/xgate/WEB-INF && ${MV} ${conf} ${conf}.sample
.endfor
	${FIND} ${WRKSRC} -name \*.orig -delete

do-install:
	${MKDIR} ${STAGEDIR}/var/log/xgate
	${MKDIR} ${STAGEDIR}${APP_HOME}/webapps/${PORTNAME}
	@cd ${WRKSRC}/${PORTNAME} && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${APP_HOME}/webapps/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docf in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${docf} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
