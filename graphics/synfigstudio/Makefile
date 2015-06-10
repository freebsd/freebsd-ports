# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	synfigstudio
PORTVERSION=	0.64.3
CATEGORIES=	graphics multimedia
MASTER_SITES=	SF/synfig/releases/${PORTVERSION}/source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vector-based 2D animation software package

LICENSE=	GPLv3

BUILD_DEPENDS=	etl>=0.04.17:${PORTSDIR}/devel/etl
LIB_DEPENDS=	libsynfig.so:${PORTSDIR}/devel/synfig
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

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
		 /DATADIRNAME/s|lib|share| ; \
		 s|<tr1/|<| ; \
		 s|::tr1||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|el_GR|el| ; \
		 s|ja_JP|ja| ; \
		 s|no_NO|no| ; \
		 s|pl_PL|pl| ; \
		 s|sk_SK|sk| ; \
		 s|sv_SE|sv|' ${WRKSRC}/po/LINGUAS

pre-build:
# FIX LC_MESSAGES
	@${LN} -sf el_GR.po ${WRKSRC}/po/el.po
	@${LN} -sf ja_JP.po ${WRKSRC}/po/ja.po
	@${LN} -sf no_NO.po ${WRKSRC}/po/no.po
	@${LN} -sf pl_PL.po ${WRKSRC}/po/pl.po
	@${LN} -sf sk_SK.po ${WRKSRC}/po/sk.po
	@${LN} -sf sv_SE.po ${WRKSRC}/po/sv.po

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	(cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
