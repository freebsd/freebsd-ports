# New ports collection makefile for:	jna
# Date created:		2010-10-01
# Whom:			Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jna
PORTVERSION=	3.2.7
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	LOCAL/olgeni
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-doc${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Java access to native shared libraries

USE_ANT=	yes
USE_GMAKE=	yes
USE_JAVA=	1.4+
USE_ZIP=	yes
USE_XORG=       x11 xt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-doc

PLIST_FILES=	%%JAVAJARDIR%%/jna-platform.jar \
		%%JAVAJARDIR%%/jna.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	javadoc platform
.endif

post-patch:
	@${CHMOD} 755 ${WRKSRC}/native/libffi/configure
	@${CHMOD} 755 ${WRKSRC}/native/libffi/install-sh

do-install:
	@${INSTALL_DATA} ${WRKSRC}/build*/freebsd-${ARCH}.jar ${JAVAJARDIR}/jna-platform.jar
	@${INSTALL_DATA} ${WRKSRC}/build*/jna.jar ${JAVAJARDIR}/jna.jar
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${DOCSRC} && ${COPYTREE_SHARE} javadoc ${DOCSDIR}
	@cd ${DOCSRC} && ${COPYTREE_SHARE} platform ${DOCSDIR}
.endif

.include <bsd.port.mk>
