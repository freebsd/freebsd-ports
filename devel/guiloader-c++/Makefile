# New ports collection makefile for:	guiloader-c++
# Date created:		11 May 2007
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	guiloader-c++
PORTVERSION=	2.10.0
CATEGORIES=	devel gnome
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	crow-designer

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A high-performance and compact GuiXml loader library

LIB_PC_DEPENDS=	guiloader.pc:${PORTSDIR}/devel/guiloader

LIB_DEPENDS+=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24
BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}

USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	atk glib20 gtk20 pango
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/${PORTNAME}/Makefile.in

.include <bsd.port.mk>
