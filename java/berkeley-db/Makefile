# New ports collection makefile for:	Berkeley DB Java
# Date created:		Feb 2, 2005
# Whom:			Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	je
PORTVERSION=	1.7.1
CATEGORIES=	java databases
MASTER_SITES=	http://downloads.sleepycat.com/ \
		ftp://ftp.sleepycat.com/releases/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Berkeley DB Java Edition

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

EXTRACT_AFTER_ARGS=       | ${TAR} -xf - --exclude '*.jar' --exclude ${DISTNAME}/docs/
USE_JAVA=	yes
USE_ANT=	yes
MAKE_ARGS+=	-verbose
MAKE_ENV+=	JAVALIBDIR="${JAVALIBDIR}"

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/lib/je.jar ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${DOCSDIR} -zxpf ${_DISTDIR}/${_DISTFILES} ${DISTNAME}/docs
	${MV} ${DOCSDIR}/${DISTNAME}/docs/* ${DOCSDIR}
	${RM} -rf ${DOCSDIR}/${DISTNAME}
.endif

.include <bsd.port.mk>
