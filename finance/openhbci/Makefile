# Created by: Heiner Strauss <heiner@bilch.com>
# $FreeBSD$

PORTNAME=	openhbci
PORTVERSION=	0.9.17.2
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.9.17
DISTNAME=	openhbci-0.9.17-2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HBCI is a bank-independent homebanking standard

DEPRECATED=	no longer maintained upstream
EXPIRATION_DATE=	2019-03-31

USES=		libtool ssl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--with-openssl-includes=${OPENSSLINC} \
		--with-openssl-libs=${OPENSSLLIB}

WRKSRC=		${WRKDIR}/${PORTNAME}-0.9.17

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||' \
		${WRKSRC}/configure \
		${WRKSRC}/src/openhbci/Makefile.in \
		${WRKSRC}/src/openhbci/core/Makefile.in

.include <bsd.port.mk>
