# Created by: Jeffrey H. Johnson <CPE1704TKS@bellsouth.net>
# $FreeBSD$

PORTNAME=	xar
PORTVERSION=	1.5.2
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenDarwin XML eXtensible ARchiver

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes

USES=		gmake libtool
USE_GNOME=	libxml2
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

.include <bsd.port.mk>
