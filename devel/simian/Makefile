# Created by: andreas@syndrom23.de
# $FreeBSD$

PORTNAME=	simian
PORTVERSION=	2.3.34
CATEGORIES=	devel java
MASTER_SITES=	http://www.harukizaemon.com/simian/

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Similarity analyser for source and other text files

LICENSE=	SIMIAN
LICENSE_NAME=	SIMIAN SOFTWARE LICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell no-auto-accept

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

RESTRICTED=	Have to agree to license before download

SUB_FILES=	simian
SUB_LIST+=	VERSION=${PORTVERSION}
PLIST_SUB+=	VERSION=${PORTVERSION}

PORTDOCS=	changes.html customers.html features.html \
		get_dotnet.png get_it_now.html \
		get_java_blue-button.gif index.html installation.html \
		simian.jpg \
		javadoc

OPTIONS_MULTI=	LANG
OPTIONS_MULTI_LANG=	JAVA MONO

OPTIONS_DEFAULT=	JAVA

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
JAVA_VERSION=	1.6+
PLIST_SUB+=	JAVA=""
SUB_LIST+=	JAVA=""
.else
PLIST_SUB+=	JAVA="@comment "
SUB_LIST+=	JAVA="@comment "
.endif

.if ${PORT_OPTIONS:MMONO}
RUN_DEPENDS+=	mono:${PORTSDIR}/lang/mono
PLIST_SUB+=	MONO=""
SUB_LIST+=	MONO=""
.else
PLIST_SUB+=	MONO="@comment "
SUB_LIST+=	MONO="@comment "
.endif

pre-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
.if !defined(PACKAGE_BUILDING) && (!defined(SIMIAN_AGREE_LICENSE) || ${SIMIAN_AGREE_LICENSE} != "yes")
	@${ECHO}	By downloading this version, you agree to the terms
	@${ECHO}	and conditions set out in the license agreement and
	@${ECHO}	you agree that, should you wish to continue using
	@${ECHO}	Simian for other than open source projects, non-
	@${ECHO}	commercial projects or evaluation purposes for a
	@${ECHO}	period greater than 15 days, you will purchase a
	@${ECHO}	license as described following URL.
	@${ECHO}
	@${ECHO}	http://www.harukizaemon.com/simian/LICENSE.txt
	@${ECHO}
	@${ECHO}	Build with SIMIAN_AGREE_LICENSE=yes to continue.
	@${ECHO}
	@${FALSE}
.endif
.endif

do-install:
	@${MKDIR} ${PREFIX}/share/xsl/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/simian.xsl ${PREFIX}/share/xsl/${PORTNAME}
	@${MKDIR} ${PREFIX}/simian/bin
.if ${PORT_OPTIONS:MJAVA}
	${INSTALL_DATA} ${WRKSRC}/bin/simian-${PORTVERSION}.jar ${PREFIX}/simian/bin
.endif
.if ${PORT_OPTIONS:MMONO}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/*.dll ${PREFIX}/simian/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/simian-${PORTVERSION}.exe ${PREFIX}/simian/bin
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/simian ${PREFIX}/bin/simian
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} \
		&& ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; \
		&& ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

.include <bsd.port.post.mk>
