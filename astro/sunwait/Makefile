PORTNAME=	sunwait
PORTVERSION=	20041208
CATEGORIES=	astro
MASTER_SITES=	http://www.risacher.org/sunwait/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Calculate sunrise and sunset
WWW=		http://www.risacher.org/sunwait/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
