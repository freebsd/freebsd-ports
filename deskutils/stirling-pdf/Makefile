PORTNAME=	stirling-pdf
PORTVERSION=	1.1.1
CATEGORIES=	deskutils java
MASTER_SITES=	https://files.stirlingpdf.com/v${PORTVERSION}/
DISTNAME=	Stirling-PDF-with-login
EXTRACT_SUFX=	.jar
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	PDF modification toolbox with web UI
WWW=		https://github.com/Stirling-Tools/Stirling-PDF \
		https://www.stirlingpdf.com/

LICENSE=	MIT

USES=		java
JAVA_VERSION=	21+
USE_RC_SUBR=	stirlingpdf

NO_ARCH=	yes
NO_BUILD=	yes

STIRLINGPDF_HOME?=	${PREFIX}/stirlingpdf
STIRLINGPDF_USER?=	stirlingpdf
STIRLINGPDF_GROUP?=	stirlingpdf

SUB_LIST+=	STIRLINGPDF_HOME=${STIRLINGPDF_HOME} \
		STIRLINGPDF_USER=${STIRLINGPDF_USER} \
		STIRLINGPDF_GROUP=${STIRLINGPDF_GROUP} \
		PREFIX=${PREFIX} \
		JAVA=${JAVA} \
		DISTNAME=${DISTNAME} \
		EXTRACT_SUFX=${EXTRACT_SUFX}

USERS=		${STIRLINGPDF_USER}
GROUPS=		${STIRLINGPDF_GROUP}

do-install:
	${MKDIR} ${STAGEDIR}${STIRLINGPDF_HOME}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${STIRLINGPDF_HOME}/${DISTNAME}${EXTRACT_SUFX}
	# Install configuration directory and sample config
	${MKDIR} ${STAGEDIR}${STIRLINGPDF_HOME}/configs
	${INSTALL_DATA} ${FILESDIR}/custom_settings.yml \
		${STAGEDIR}${STIRLINGPDF_HOME}/configs/custom_settings.yml.sample

post-install:
	${ECHO_CMD} "stirlingpdf/Stirling-PDF-with-login.jar" >> ${TMPPLIST}
	${ECHO_CMD} "@owner ${STIRLINGPDF_USER}" >> ${TMPPLIST}
	${ECHO_CMD} "@group ${STIRLINGPDF_GROUP}" >> ${TMPPLIST}
	${ECHO_CMD} "@dir(,,740) stirlingpdf" >> ${TMPPLIST}
	${ECHO_CMD} "@dir(,,740) stirlingpdf/configs" >> ${TMPPLIST}
	${ECHO_CMD} "@sample stirlingpdf/configs/custom_settings.yml.sample" >> ${TMPPLIST}

.include <bsd.port.mk>
