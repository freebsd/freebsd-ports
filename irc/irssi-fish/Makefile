# Created by: Jens Holmqvist <zparta@hispan.se>
# $FreeBSD$

PORTNAME=	irssi-fish
DISTVERSION=	1.4.20160122
PORTREVISION=	1
CATEGORIES=	irc security

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Encryption plugin for irssi

BUILD_DEPENDS=	${LOCALBASE}/include/glib-2.0/glib.h:devel/glib20 \
		${LOCALBASE}/include/irssi/src/common.h:irc/irssi
RUN_DEPENDS=	irssi:irc/irssi

USE_GITHUB=	yes
GH_PROJECT=	FiSH-irssi
GH_ACCOUNT=	falsovsky
GH_TAGNAME=	2b0c1c09

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

PLIST_FILES=	lib/irssi/modules/libfish.so
PORTDOCS=	README.md FiSH-irssi.txt

USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes

post-patch:
	${REINPLACE_CMD} -e "s,/usr/local,${LOCALBASE},g" \
			 -e "s,share/doc/FiSH-irssi,${DOCSDIR_REL},g" ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
