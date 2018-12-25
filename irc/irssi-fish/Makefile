# Created by: Jens Holmqvist <zparta@hispan.se>
# $FreeBSD$

PORTNAME=	irssi-fish
DISTVERSION=	1.5.20181025
CATEGORIES=	irc security

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Encryption plugin for irssi

BUILD_DEPENDS=	${LOCALBASE}/include/glib-2.0/glib.h:devel/glib20 \
		${LOCALBASE}/include/irssi/src/common.h:irc/irssi
RUN_DEPENDS=	irssi:irc/irssi

USES=		cmake gnome pkgconfig ssl

USE_GNOME+=	glib20
USE_LDCONFIG=	yes
USE_GITHUB=	yes

GH_PROJECT=	FiSH-irssi
GH_ACCOUNT=	falsovsky
GH_TAGNAME=	15d199b6

CMAKE_ARGS=	-DOPENSSL_FOUND=1 \
		-DOPENSSL_INCLUDE_DIRS=${OPENSSLINC} \
		-DOPENSSL_LIBRARY_DIRS=${OPENSSLLIB}

PLIST_FILES=	lib/irssi/modules/libfish.so
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s,/usr/local,${LOCALBASE},g" \
			 -e "s,share/doc/FiSH-irssi,${DOCSDIR_REL},g" \
			 ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
