# ex:ts=8
# New ports collection makefile for:	poedit
# Date created:			Mar 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poedit
PORTVERSION=	1.1.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
#PATCH_SITES=	${MASTER_SITES}
#PATCHFILES=	poedit-1.1.5-wxwin-2.3.1.patch

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk-devel \
		db3:${PORTSDIR}/databases/db3 \
		giconv:${PORTSDIR}/converters/libiconv

PATCH_DIST_ARGS=	-d ${PATCH_WRKSRC} -E ${PATCH_DIST_STRIP} -p1
USE_X_PREFIX=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgiconv"
USE_GMAKE=	yes

MAN1=	poedit.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.else
CONFIGURE_ARGS=	--without-gnome
.endif

.include <bsd.port.post.mk>
