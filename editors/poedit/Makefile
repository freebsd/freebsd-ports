# ex:ts=8
# New ports collection makefile for:	poedit
# Date created:			Mar 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poedit
PORTVERSION=	1.1.8
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
#PATCH_SITES=	${MASTER_SITES}
#PATCHFILES=	poedit-1.1.5-wxwin-2.3.1.patch

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext \
		wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk-devel \
		db3.3:${PORTSDIR}/databases/db3

PATCH_DIST_ARGS=	-d ${PATCH_WRKSRC} -E ${PATCH_DIST_STRIP} -p1
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -liconv ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--datadir=${PREFIX}/share
USE_GMAKE=	yes

MAN1=	poedit.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.else
CONFIGURE_ARGS+=	--without-gnome
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$(datadir)/gnome/|\$$(datadir)/|g ; \
		s|\$$(datadir)/locale|\$$(prefix)/share/locale|g'

.include <bsd.port.post.mk>
