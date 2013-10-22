# $FreeBSD$

PORTNAME=	ebview
PORTVERSION=	0.3.6
PORTREVISION=	17
CATEGORIES=	japanese
MASTER_SITES=	SF
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic Book Viewer

LIB_DEPENDS=	eb:${PORTSDIR}/japanese/eb

CONFLICTS=	ja-ebview-0*

USES=		pkgconfig
USE_GNOME=	gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
CONFIGURE_ARGS+=--with-eb-conf=${LOCALBASE}/etc/eb.conf
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	ebview.desktop

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|-pthread|${PTHREAD_LIBS:S/"//g}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|#define GTK_DISABLE_DEPRECATED 1||g' \
		${WRKSRC}/src/ebview.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/pixmaps/ebview.xpm ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKDIR}/${SUB_FILES} ${PREFIX}/share/applications/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
