# Created by: Jose Marques <noway@nohow.demon.co.uk>

PORTNAME=	cos
PORTVERSION=	2002.11.05
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	java devel
MASTER_SITES=	http://www.servlets.com/cos/ \
		http://www.oreilly.com.tw/bookcode/
DISTNAME=	${PORTNAME}-05Nov2002

MAINTAINER=	java@FreeBSD.org
COMMENT=	The O'Reilly package of utility classes for servlet developers

# Converted from RESTRICTED
LICENSE=	cos
LICENSE_NAME=	cos
LICENSE_TEXT=	Special conditions apply for commercial use, see licence
LICENSE_PERMS=	auto-accept

NO_WRKSUBDIR=	yes
USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes
DATAFILES=	readme.txt license.txt doc
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/cos.jar ${STAGEDIR}${JAVAJARDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${DATAFILES}" ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/upload.war ${STAGEDIR}${DATADIR}/doc

.include <bsd.port.mk>
