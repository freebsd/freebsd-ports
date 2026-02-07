PORTNAME=	bicom
PORTVERSION=	1.01
CATEGORIES=	archivers
MASTER_SITES=	http://www.mirrorservice.org/pub/minix/distfiles/backup/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data compressor in the PPM family
WWW=		http://www3.sympatico.ca/mt0000/bicom/

# Converted from RESTRICTED
LICENSE=	BICOM
LICENSE_NAME=	bicom
LICENSE_TEXT=	Contact author personally regarding commercial use
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		dos2unix zip
DOS2UNIX_GLOB=	*.cpp *.h
NO_WRKSUBDIR=	yes
MAKEFILE=	${FILESDIR}/Makefile

PLIST_FILES=	bin/bicom

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bicom/bicom ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
