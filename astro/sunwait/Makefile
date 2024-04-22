PORTNAME=	sunwait
DISTVERSION=	0.9.1
PORTEPOCH=	1
CATEGORIES=	astro
MASTER_SITES=	https://www.risacher.org/sunwait/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Calculate sunrise and sunset
WWW=		http://www.risacher.org/sunwait/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	risacher

MAKEFILE=	makefile
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
