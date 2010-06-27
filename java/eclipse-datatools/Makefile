# New ports collection makefile for:	eclipse-datatools
# Date created:		Sun  1 Apr 2007 22:18:17 UTC
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	datatools
DISTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	java devel databases
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/datatools/downloads/,}
MASTER_SITE_SUBDIR=	${PORTVERSION:R}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	dtp_${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Data Tools Platform for the Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/eclipse/features/org.eclipse.emf_2.3.2.v200802051830/feature.xml:${PORTSDIR}/java/eclipse-emf \
		${LOCALBASE}/eclipse/features/org.eclipse.gef_3.3.2.v20080129/feature.xml:${PORTSDIR}/java/eclipse-gef

LICENSE=	EPL

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native

post-extract:
# avoid empty dirs since they break the automated PLIST generation
	@${FIND} ${WRKSRC} -type d -empty \
		-exec ${TOUCH} "{}/.keep_me" \;

do-install:
# create destination dir
		@${MKDIR} ${PREFIX}/eclipse
# install both files and directories
		@(cd ${WRKSRC}/eclipse && \
			${FIND} -s features plugins -type d \
				-exec ${MKDIR} "${PREFIX}/eclipse/{}" \; && \
			${FIND} -s features plugins -not -type d \
				-exec ${INSTALL_DATA} "{}" "${PREFIX}/eclipse/{}" \; \
		)

# used to manually generate the plist files
generate-plist-locally: build
# annotate installation files
	@(cd ${WRKSRC}/eclipse && ${FIND} -s features plugins -not -type d) \
		| ${SED} -ne 's,^,eclipse/,p' > ${PLIST}
# annotate installation directories
	@(cd ${WRKSRC}/eclipse && ${FIND} -s -d features plugins -type d) \
		| ${GREP} -vE '^plugins$$|^features$$' \
		| ${SED} -ne 's,^,@dirrm eclipse/,p' >> ${PLIST}

.include <bsd.port.mk>
