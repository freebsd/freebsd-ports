PORTNAME=	bicom
PORTVERSION=	1.01
CATEGORIES=	archivers
MASTER_SITES=	http://www3.sympatico.ca/mt0000/bicom/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data compressor in the PPM family

# Converted from RESTRICTED
LICENSE=	BICOM
LICENSE_NAME=	bicom
LICENSE_TEXT=	Contact author personally regarding commercial use
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		zip
NO_WRKSUBDIR=	yes
MAKEFILE=	${FILESDIR}/Makefile

PLIST_FILES=	bin/bicom

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bicom/bicom ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
