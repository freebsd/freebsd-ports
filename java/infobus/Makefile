# Created by: Jose Marques
# $FreeBSD$

PORTNAME=	infobus
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	java devel
DISTNAME=	ib12

MAINTAINER=	java@FreeBSD.org
COMMENT=	Enables dynamic exchange of data between JavaBeans(TM)

USES=		zip
USE_JAVA=	YES
JAVA_VERSION=	1.6+

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_CDROM=	See the license

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	You must manually fetch the distribution from http://java.sun.com/products/archive/javabeans/infobus/downloads.html and place it in ${DISTDIR} then run make again
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/infobus.jar ${JAVAJARDIR}/
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.java ${EXAMPLESDIR}
.for i in examples.mak makefile moneyman.mf ReadMe.html ReadRowset.html coffee6.gif
	${INSTALL_DATA} ${WRKSRC}/${i} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in LICENSE.HTML ReadMe.html coffee6.gif
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	cd ${WRKSRC}/doc && \
		${FIND} . | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
