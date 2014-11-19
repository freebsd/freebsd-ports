# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	lianliankan
DISTVERSION=	2.3beta1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/llk-linux/llk-linux-source/${DISTVERSION}
DISTNAME=	llk_linux-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tile matching game

LICENSE=	GPLv2 # or later

USES=		autoreconf libtool pkgconfig
USE_GNOME=	gtk20 esound
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

DATADIR=	${PREFIX}/share/llk_linux

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${RM} ${WRKSRC}/INSTALL
	@${REINPLACE_CMD} -e 's|po include src|po src|' \
		-e '/llk_linuxdocdir/,/EXTRA_DIST =/ d' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|gdk_pixbuf_unref|g_object_unref| ; \
		s|OK,message|OK, "%s", message|' \
		${WRKSRC}/src/main.c
	@${REINPLACE_CMD} -e 's|Pos.__pos|Pos|' \
		${WRKSRC}/src/pak/pak.c

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|po||' \
		${WRKSRC}/Makefile.am
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/lianliankan.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
