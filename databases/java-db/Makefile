# ex:ts=8
# Ports collection makefile for:	Berkeley DB Java Edition
# Date created:			Sep 18, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	db
PORTVERSION=	3.0.12
CATEGORIES=	databases java
MASTER_SITES=	http://downloads.sleepycat.com/ \
		ftp://ftp.sleepycat.com/releases/
PKGNAMEPREFIX=	java-
DISTNAME=	je-${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Berkeley DB Java Edition

BUILD_DEPENDS=	${JAVAJARDIR}/junit.jar:${PORTSDIR}/java/junit

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes

PLIST_FILES=	${JAVAJARDIR:S,^${PREFIX}/,,}/je.jar

.if !defined(NOPORTDOCS)
DOCSDIR=	${TARGETDIR}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${TARGETDIR}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} "s,/usr/local,${TARGETDIR}," ${WRKSRC}/build.xml

do-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/je.jar ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}

post-install:
	@${FIND} ${EXAMPLESDIR} ! -type d | \
		${SED} -e "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} -e "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
