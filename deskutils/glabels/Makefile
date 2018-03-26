# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	glabels
PORTVERSION=	2.2.8
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program to create labels and business cards

OPTIONS_DEFINE=	EVOLUTION
EVOLUTION_DESC=	Support evolution data server

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info tar:bzip2
USE_GNOME=	gnomeprefix libgnomeui gnomedocutils intlhack
INSTALLS_OMF=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-desktopdb --disable-update-mimedb
CPPFLAGS+=	-I${LOCALBASE}/include -DGLIB_COMPILATION
LDFLAGS+=	-L${LOCALBASE}/lib

EVOLUTION_USE=	GNOME=evolutiondataserver
EVOLUTION_CONFIGURE_WITH=	libebook

post-patch:
	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib\.h|g' \
		${WRKSRC}/iec16022-0.2.1/*.c
	@${REINPLACE_CMD} 's/_LDADD =/& -lm/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
