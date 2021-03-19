# $FreeBSD$

PORTNAME=	dnsdbflex
PORTVERSION=	1.0.5
DISTVERSIONPREFIX=	v
CATEGORIES=	dns

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Tool to use the DNSDB Flexible Search API extensions

LICENSE=		APACHE20
LICENSE_FILE_APACHE20=	${WRKSRC}/Apache-2.0

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libcurl.so:ftp/curl

USES=		compiler:c11 localbase
USE_GITHUB=	yes
GH_ACCOUNT=	farsightsec

PORTSCOUT=	limit:^[0-9]*\.[0-9]*\.[0-9]*$$

PLIST_FILES=		bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
