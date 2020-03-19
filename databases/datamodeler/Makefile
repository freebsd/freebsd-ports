# Created by: jjuanino@gmail.com
# $FreeBSD$

PORTNAME=	datamodeler
PORTVERSION=	19.1.0.081.0911
DISTVERSIONSUFFIX=-1
CATEGORIES=	databases java
MASTER_SITES=	#http://www.oracle.com/technetwork/developer-tools/datamodeler/downloads/index.html
DISTNAME=	${PORTNAME}-${PORTVERSION}${DISTVERSIONSUFFIX}.noarch
EXTRACT_SUFX=	.rpm
DIST_SUBDIR=	oracle

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Database modeling tool

EXTRACT_DEPENDS=rpm2cpio.pl:archivers/rpm2cpio
RUN_DEPENDS=	bash:shells/bash ${JAVA_HOME}/bin/javafxpackager:java/openjfx8-devel

USES=		gnome

#http://www.oracle.com/technetwork/licenses/sqldev-license-152021.html
LICENSE_NAME=	OTN
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror

USE_JAVA=	yes
INSTALLS_ICONS=	yes

JAVA_VERSION=	1.8+

NO_BUILD=	yes

RESTRICTED=	Packaging prohibited by Oracle license
NO_CDROM=	Packaging prohibited by Oracle license

DEPRECATED=	depends on expiring java/openjfx8-devel
EXPIRATION_DATE=	2020-11-30

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/opt/${PORTNAME}
SUB_FILES=	${PORTNAME}.script.sh
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

OPTIONS_DEFINE=	DOCS

# configure desktop file
post-patch:
	@${REINPLACE_CMD} -e \
	    's|/opt/datamodeler/icon.png|${PREFIX}/share/icons/hicolor/128x128/apps/${PORTNAME}.png|' \
	    ${WRKSRC}/datamodeler.desktop
	@${ECHO} "Categories=Utility" >> ${WRKSRC}/datamodeler.desktop

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	due to Oracle license restrictions, you must fetch the source \
distribution manually. Please access \
http://www.oracle.com/technetwork/developer-tools/datamodeler/downloads/index.html \
with a web browser and follow the link for the ${DISTFILES}. You will be \
required to register and log in, but you can create an account on that \
page. After registration and accepting the Oracle License, download the \
distribution file, ${DISTFILES}, into ${DISTDIR}/${DIST_SUBDIR}/ and then \
restart this installation.
.endif

do-install:
	${ECHO_MSG} -n ">> Installing scripts..."
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.script.sh ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	${ECHO_MSG} " [ DONE ]"

.for d in configuration datamodeler dropins dvt equinox external ide \
    jdbc jdev jlib module modules netbeans rdbms sleepycat \
    sqldeveloper svnkit
	${ECHO_MSG} -n ">> Installing data directory '${d}'..."
	cd ${WRKSRC} && ${FIND} ${d} -type d \
		-exec ${MKDIR} ${STAGEDIR}/${DATADIR}/\{} \;
	cd ${WRKSRC} && ${FIND} ${d} -type f \
		-not -name "*.exe" \
		-not -name "*.bak" \
		-not -name "*.dll" \
		-not -name "*.so" \
		-exec ${INSTALL_DATA} \{} ${STAGEDIR}/${DATADIR}/\{} \;
	${ECHO_MSG} " [ DONE ]"
.endfor

	${ECHO_MSG} -n ">> Installing icon and desktop file ..."
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/applications/ \
	    ${STAGEDIR}/${PREFIX}/share/icons/hicolor/128x128/apps/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}/${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/icon.png ${STAGEDIR}/${PREFIX}/share/icons/hicolor/128x128/apps/datamodeler.png

	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>
