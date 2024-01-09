PORTNAME=	doctorj
PORTVERSION=	5.1.2
PORTREVISION=	3
CATEGORIES=	devel java
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for analyzing Java code and documentation
WWW=		https://doctorj.sourceforge.net/

USE_JAVA=	yes
USE_ANT=	yes

ALL_TARGET=	jarfile

PLIST_FILES=	%%JAVAJARDIR%%/doctorj.jar share/man/man1/doctorj.1.gz

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/share/doctorj/doctorj.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/doctorj.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
