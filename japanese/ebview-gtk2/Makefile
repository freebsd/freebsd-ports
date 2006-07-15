# New ports collection makefile for:	ebview-gtk2
# Date Created:				7 Dec 2003
# Whom:					<faust@ua.airnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	ebview
PORTVERSION=	0.3.6
PORTREVISION=	6
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic Book Viewer

BROKEN=		fails to install due to directory problem

LIB_DEPENDS=	eb.10:${PORTSDIR}/japanese/eb

CONFLICTS=	ja-ebview-0*

USE_GNOME=	gtk20 gnometarget
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-eb-conf=${LOCALBASE}/etc/eb.conf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

SUB_FILES=	ebview.desktop

post-patch:
	@${REINPLACE_CMD} -e \
		's|-pthread|${PTHREAD_LIBS:S/"//g}|g' ${WRKSRC}/configure

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
