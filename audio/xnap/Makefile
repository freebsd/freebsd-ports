# New ports collection makefile for:	XNap
# Date created:				Mon Nov 19 22:02:27 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XNap
PORTVERSION=	1.3.p1
CATEGORIES=	audio java net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
DISTNAME=	${PORTNAME:L}-${PORTVERSION:S/.p/-pre/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre \
		${LOCALBASE}/jdk1.3.1/bin/java:${PORTSDIR}/java/jdk13

NO_BUILD=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR}

JAVAVM=		${LOCALBASE}/bin/javavm
JAR_DIR=	share/java/jar/${PORTNAME}

DOC_FILES=      AUTHORS CHANGES COMMANDS COPYING COPYING.LIB README \
		TODO

post-patch:
	@${SED} -e "s|%%JAR_DIR%%|${JAR_DIR}|;s|%%JAVAVM%%|${JAVAVM}|; \
		s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
	@${MKDIR} ${PREFIX}/${JAR_DIR}
	@${INSTALL_DATA} ${WRKSRC}/xnap.jar ${PREFIX}/${JAR_DIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME:L}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
