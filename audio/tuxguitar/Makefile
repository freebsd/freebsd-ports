# New ports collection makefile for:   tuxguitar
# Date created:        26 April 2007
# Whom:                Pietro Cerutti (gahr@gahr.ch)
#
# $FreeBSD$
#

PORTNAME=	tuxguitar
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	audio java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTNAME=	TuxGuitar-0.9.1-src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Multitrack tablature editor and player

BUILD_DEPENDS=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt \
		${JAVALIBDIR}/itext.jar:${PORTSDIR}/devel/itext

RUN_DEPENDS=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt \
		${JAVALIBDIR}/itext.jar:${PORTSDIR}/devel/itext

WRKSRC=		${WRKDIR}/TuxGuitar-0.9.1-src

USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ANT=	yes

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' \
	${WRKSRC}/build.properties

do-install:
	${INSTALL_DATA} ${WRKSRC}/TuxGuitar.jar ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tuxguitar ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/share/ && ${COPYTREE_SHARE} \* ${DATADIR}/)

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
