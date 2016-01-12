# Created by: Ulrich Spoerlein <uspoerlein@gmail.com>
# $FreeBSD$

PORTNAME=	librcd
PORTVERSION=	0.1.14
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://dside.dyndns.org/files/rusxmms/ \
		LOCAL/fluffy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library used by rusxmms for autodetection of Russian charset

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix tar:bzip2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
