# New ports collection makefile for:	ebview-gtk2
# Date Created:				7 Dec 2003
# Whom:					<faust@ua.airnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	ebview
PORTVERSION=	0.3.6
PORTREVISION=	12
CATEGORIES=	japanese
MASTER_SITES=	SF
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic Book Viewer

LIB_DEPENDS=	eb.14:${PORTSDIR}/japanese/eb

CONFLICTS=	ja-ebview-0*

USE_GNOME=	gtk20 gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-eb-conf=${LOCALBASE}/etc/eb.conf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

SUB_FILES=	ebview.desktop

post-patch:
	@${REINPLACE_CMD} -e \
		's|-pthread|${PTHREAD_LIBS:S/"//g}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|#define GTK_DISABLE_DEPRECATED 1||g' \
		${WRKSRC}/src/ebview.c

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/pixmaps/ebview.xpm ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKDIR}/${SUB_FILES} ${PREFIX}/share/applications/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
