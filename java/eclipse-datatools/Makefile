# New ports collection makefile for:	eclipse-datatools
# Date created:		Sun  1 Apr 2007 22:18:17 UTC
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	datatools
DISTVERSION=	1.5.1_101607
CATEGORIES=	java devel databases
MASTER_SITE_SUBDIR=	1.5
PKGNAMEPREFIX=	eclipse-
DISTNAME=	dtp-sdk_${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Data Tools Platform for the Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/eclipse/features/org.eclipse.emf_2.2.4.v200710030400/feature.xml:${PORTSDIR}/java/eclipse-emf \
		${LOCALBASE}/eclipse/features/org.eclipse.gef_3.2.2.v20070208/feature.xml:${PORTSDIR}/java/eclipse-gef

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
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

.include <bsd.port.pre.mk>

.include "${.CURDIR}/Makefile.master-sites"

.include <bsd.port.post.mk>
