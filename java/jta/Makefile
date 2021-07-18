# Created by: Alex Dupre <ale@FreeBSD.org>

PORTNAME=	jta
PORTVERSION=	1.0.1
CATEGORIES=	java devel
MASTER_SITES=	#
DISTNAME=	${PORTNAME}-spec${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Transaction API (JTA)

# Converted from NO_CDROM
LICENSE=	jta
LICENSE_NAME=	jta
LICENSE_TEXT=	See the license
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		zip
USE_JAVA=	yes

NO_BUILD=	yes
DOWNLOAD_URL=	http://download.oracle.com/otndocs/jcp/7286-jta-${PORTVERSION}-spec-oth-JSpec/?submit=Download

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	${DISTNAME}.pdf javadocs

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		you must manually fetch the distribution from ${DOWNLOAD_URL} and place it in ${DISTDIR} then run make again
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/${DISTNAME}.pdf ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} javadocs ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
