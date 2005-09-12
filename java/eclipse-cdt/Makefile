# New ports collection makefile for:	eclipse-cdt
# Date created:				March 1, 2004
# Whom:					gldisater@gldis.ca
#
# $FreeBSD$
#

PORTNAME=	cdt
PORTVERSION=	3.0.0
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/cdt/releases/eclipse3.1/dist/${PORTVERSION}/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	org.eclipse.cdt-${PORTVERSION}-linux.${ECLIPSE_ARCH}
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	C/C++ IDE for Eclipse

RUN_DEPENDS=	${LOCALBASE}/eclipse:${PORTSDIR}/java/eclipse

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

ECLIPSE_ARCH=	x86

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins  ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse
		@(cd ${WRKSRC}; ${FIND} -s eclipse -not -type d) >> ${TMPPLIST}
		@(cd ${WRKSRC}; ${FIND} -s -d eclipse -type d) \
		  | ${GREP} -vE 'eclipse$$|eclipse/plugins$$|eclipse/features$$' \
		  | ${SED} -ne 's,^,@dirrm ,p' >> ${TMPPLIST}
.include <bsd.port.mk>
