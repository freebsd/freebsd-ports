# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	dee
PORTVERSION=	1.2.7
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/151383425/ \
	https://launchpad.net/${PORTNAME}/1.0/${PORTVERSION}/+download/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Model to synchronize multiple instances over DBus

LICENSE=	GPLv3

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libicutu.so:${PORTSDIR}/devel/icu

USES=	gmake pkgconfig pathfix libtool
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 introspection:build
USE_PYTHON=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-gtk-doc-html \
	--disable-tests \
	--disable-gcov \
	--enable-introspection=yes \
	--without-html-dir
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 300
USE_GNOME+=	py3gobject3
.else
USE_GNOME+=	pygobject3
.endif

post-patch:
	${REINPLACE_CMD} -e 's| -Wempty-body||' ${WRKSRC}/configure

.include <bsd.port.post.mk>
