# New ports collection makefile for:	simian
# Date created:				July 8, 2005
# Whom:					andreas@syndrom23.de
#
# $FreeBSD$
#

PORTNAME=	simian
PORTVERSION=	2.2.24
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://www.redhillconsulting.com.au/products/simian/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Similarity analyser for source and other text files

.if defined(WITHOUT_JAVA) && !defined(WITH_MONO)
WITH_MONO=	yes
.endif

.if defined(WITH_MONO)
RUN_DEPENDS+=	mono:${PORTSDIR}/lang/mono
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

.if !defined(WITHOUT_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.4+
PLIST_SUB+=	JAVA=""
SUB_LIST+=	JAVA=""
.else
PLIST_SUB+=	JAVA="@comment "
SUB_LIST+=	JAVA="@comment "
.endif

.if defined(WITH_MONO)
PLIST_SUB+=	MONO=""
SUB_LIST+=	MONO=""
.else
PLIST_SUB+=	MONO="@comment "
SUB_LIST+=	MONO="@comment "
.endif

.if defined(PACKAGE_BUILDING)
RESTRICTED=	Have to agree to license before download
.endif

SUB_FILES=	simian
SUB_LIST+=	VERSION=${PORTVERSION}
PLIST_SUB+=	VERSION=${PORTVERSION}

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE.txt changes.html customers.html features.html \
		future_plans.html get_dotnet.png get_it_now.html \
		get_java_blue-button.gif index.html installation.html \
		menu.html overview.html simian.jpg \
		javadoc
.endif

.include <bsd.port.pre.mk>

pre-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
.if !defined(PACKAGE_BUILDING) && (!defined(SIMIAN_AGREE_LICENSE) || ${SIMIAN_AGREE_LICENSE} != "yes")
	@${ECHO}	By downloading this version, you agree to the terms
	@${ECHO}	and conditions set out in the license agreement and
	@${ECHO}	you agree that, should you wish to continue using
	@${ECHO}	Simian for other than open source projects, non-
	@${ECHO}	commercial projects or evaluation purposes for a
	@${ECHO}	period greater than 15 days, you will purchase a
	@${ECHO}	license as described above.
	@${ECHO}
	@${ECHO}	http://www.redhillconsulting.com.au/products/simian/LICENSE.txt
	@${ECHO}
	@${ECHO}	Build with SIMIAN_AGREE_LICENSE=yes to continue.
	@${ECHO}
	@${FALSE}
.endif
.endif

do-install:
	@${MKDIR} ${PREFIX}/share/xsl/${PORTNAME}
	${CP} ${WRKSRC}/simian.xsl ${PREFIX}/share/xsl/${PORTNAME}
	@${MKDIR} ${PREFIX}/simian
	@${MKDIR} ${PREFIX}/simian/bin
.if !defined(WITHOUT_JAVA)
	${CP} ${WRKSRC}/bin/simian-${PORTVERSION}.jar ${PREFIX}/simian/bin
.endif
.if defined(WITH_MONO)
	${CP} ${WRKSRC}/bin/*.dll ${PREFIX}/simian/bin
	${CP} ${WRKSRC}/bin/simian-${PORTVERSION}.exe ${PREFIX}/simian/bin
.endif
	${CP} ${WRKSRC}/simian ${PREFIX}/bin/simian
	${CHMOD} a+x ${PREFIX}/bin/simian
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} \
		&& ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; \
		&& ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

.include <bsd.port.post.mk>
