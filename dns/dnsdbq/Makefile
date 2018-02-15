# $FreeBSD$

PORTNAME=	dnsdbq
PORTVERSION=	0.0.20180215
CATEGORIES=	dns

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Shortened version of the dnsdb query testing tool

LICENSE=		APACHE20 ISCL
LICENSE_COMB=		multi
LICENSE_FILE_APACHE20=	${WRKSRC}/Apache-2.0
LICENSE_FILE_ISCL=	${WRKSRC}/ISC

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libcurl.so:ftp/curl

USES=		localbase
USE_GITHUB=	yes
GH_ACCOUNT=	dnsdb
GH_TAGNAME=	273f985f03a4b92a8d641f064dc54faf28222e36

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
