# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libidn2
PORTVERSION=	0.11
CATEGORIES=	dns
MASTER_SITES=	GNU_ALPHA/libidn

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of IDNA2008 internationalized domain names

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		charsetfix gmake iconv libtool localbase shebangfix
USE_LDCONFIG=	yes

INFO=		libidn2
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
