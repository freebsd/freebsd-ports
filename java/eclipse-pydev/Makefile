# New ports collection makefile for:	eclipse-pydev
# Date created:		2007-11-16
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pydev
PORTVERSION=	1.3.18
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	java devel python
MASTER_SITES=	SF
PKGNAMEPREFIX=	eclipse-
DISTFILES=	org.python.pydev.feature-${PORTVERSION:S,.,_,g}.zip

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Eclipse plugin for Python and Jython development

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

JAVA_OS=	native
JAVA_VENDOR=	bsdjava
JAVA_VERSION=	1.5+

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_JAVA=	yes
USE_ZIP=	yes

do-install:
	@cd ${WRKDIR} && ${CP} -R eclipse ${PREFIX}/;

post-install:
	@cd ${WRKDIR}; \
	${ECHO_CMD} "@comment pkg-plist automatically generated" >> ${TMPPLIST}; \
	${FIND} -s eclipse -type f -exec ${ECHO_CMD} {} ";" >> ${TMPPLIST}; \
	${FIND} -s eclipse -type d | ${SORT} -r | ${GREP} -vE '^eclipse$$|^eclipse/plugins$$|^eclipse/features$$' | ${SED} -ne 's,^,@dirrm ,p' >> ${TMPPLIST};
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
