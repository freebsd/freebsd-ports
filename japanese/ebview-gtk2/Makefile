# $FreeBSD$

PORTNAME=	ebview
PORTVERSION=	0.3.6
PORTREVISION=	19
CATEGORIES=	japanese
MASTER_SITES=	SF
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic Book Viewer

LICENSE=	GPLv2+

LIB_DEPENDS=	libeb.so:japanese/eb

CONFLICTS=	ja-ebview-[0-9]*

USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20 pangox-compat
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-eb-conf=${LOCALBASE}/etc/eb.conf

SUB_FILES=	ebview.desktop

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|#define GTK_DISABLE_DEPRECATED 1||g' \
		${WRKSRC}/src/ebview.c

post-install:
	(cd ${WRKDIR} && ${INSTALL_DATA} ${SUB_FILES} \
		${STAGEDIR}${DESKTOPDIR})
	(cd ${WRKSRC}/pixmaps && ${INSTALL_DATA} ebview.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ChangeLog README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
