# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	synfigstudio
PORTVERSION=	0.63.05
PORTREVISION=	5
CATEGORIES=	graphics multimedia
MASTER_SITES=	SF/synfig/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vector-based 2D animation software package

LICENSE=	GPLv3

BUILD_DEPENDS=	etl>=0.04.17:${PORTSDIR}/devel/etl
LIB_DEPENDS=	libsynfig.so:${PORTSDIR}/devel/synfig

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info
USE_GNOME=	gtkmm24
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-mimedb
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/optimization_flags/s|CXXFLAGS=|#CXXFLAGS=| ; \
		 /optimization_flags/s|CFLAGS=|#CFLAGS=| ; \
		 s|sk_SK|sk| ; \
		 s|<tr1/|<| ; \
		 s|::tr1||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|<synfig/string_decl.h>|<synfig/string.h>|' \
		${WRKSRC}/src/gui/preview.cpp
	@${REINPLACE_CMD} -e \
		's|\(get_value_node()\).\(clone()\)|\1->\2|' \
		${WRKSRC}/src/gui/states/state_draw.cpp
	@${REINPLACE_CMD} -e \
		's|\(old_value_node\).\(clone()\)|\1->\2|' \
		${WRKSRC}/src/synfigapp/actions/layerparamdisconnect.cpp

post-build:
# FIX LC_MESSAGES
	@${LN} -sf sk_SK.gmo ${WRKSRC}/po/sk.gmo

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	(cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
