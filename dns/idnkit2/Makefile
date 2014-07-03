# Created by: Rafal Lesniak <fbsd@grid.einherjar.de>
# $FreeBSD$

PORTNAME=	idnkit
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://jprs.co.jp/idn/
PKGNAMESUFFIX=	2

MAINTAINER=	fbsd@grid.einherjar.de
COMMENT=	Internationalized Domain Name toolkit 2

LICENSE_PERMS=	# permissive
LICENSE_NAME=	OSCL
LICENSE_FILE=	LICENSE.txt

CONFLICTS_INSTALL=	idnkit-1.*

USES=		iconv libtool tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_BASE}

USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
