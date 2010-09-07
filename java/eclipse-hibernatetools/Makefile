# New ports collection makefile for:	Eclipse Hibernate Tools
# Date created:		Mon 24 Dec 2007 11:16:09 UTC
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hibernatetools
DISTVERSION=	3.2.3.GA
PORTREVISION=	2
CATEGORIES=	java devel databases
MASTER_SITES=	SF/jboss/JBossTools/JBossTools%202.1.2.GA
PKGNAMEPREFIX=	eclipse-
DISTNAME=	HibernateTools-${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Hibernate3 Tools for the Eclipse IDE

## XXX - Notify the maintainer if the dependencies on either
## java/eclipse-gef of java/eclipse-webtools change
RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/share/eclipse/dropins/gef:${PORTSDIR}/java/eclipse-gef \
		${LOCALBASE}/share/eclipse/dropins/webtools:${PORTSDIR}/java/eclipse-webtools

LICENSE=	EPL LGPL3
LICENSE_COMB=	multi

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
	@${MKDIR} ${PREFIX}/lib/eclipse
# install both files and directories
	@(cd ${WRKSRC} && \
		${FIND} -s features plugins -type d \
			-exec ${MKDIR} "${PREFIX}/lib/eclipse/{}" \; && \
		${FIND} -s features plugins -not -type d \
			-exec ${INSTALL_DATA} "{}" "${PREFIX}/lib/eclipse/{}" \; \
	)

# used to manually generate the plist files
generate-plist-locally: build
# annotate installation files
	@(cd ${WRKSRC} && ${FIND} -s features plugins -not -type d) \
		| ${SED} -ne 's,^,lib/eclipse/,p' > ${PLIST}
# annotate installation directories
	@(cd ${WRKSRC} && ${FIND} -s -d features plugins -type d) \
		| ${GREP} -vE '^plugins$$|^features$$' \
		| ${SED} -ne 's,^,@dirrm lib/eclipse/,p' >> ${PLIST}

.include <bsd.port.mk>
