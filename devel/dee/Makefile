# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	dee
PORTVERSION=	1.2.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/151383425/ \
	https://launchpad.net/${PORTNAME}/1.0/${PORTVERSION}/+download/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Model to synchronize multiple instances over DBus

LICENSE=	GPLv3

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libicutu.so:devel/icu

USES=		gmake libtool pkgconfig pathfix python:2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 introspection:build pygobject3
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-gtk-doc-html \
	--disable-tests \
	--disable-gcov \
	--enable-introspection=yes \
	--without-html-dir
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e 's| -Wempty-body||' ${WRKSRC}/configure

.include <bsd.port.mk>
