# New ports collection makefile for:	crow
# Date created:		11 May 2007
# Whom:			Yinghong.Liu <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	crow
PORTVERSION=	2.11.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	crow-designer

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modern GUI builder for the GTK+ toolkit

LIB_PC_DEPENDS=	guiloader-c++.pc:${PORTSDIR}/devel/guiloader-c++

LIB_DEPENDS+=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g} \
		xdg-desktop-menu:${PORTSDIR}/devel/xdg-utils

USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	atk glib20 gtk20 pango
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/${PORTNAME}/Makefile.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		Fails to compile
.endif

.include <bsd.port.post.mk>
