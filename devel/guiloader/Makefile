# New ports collection makefile for:	guiloader
# Date created:		11 May 2007
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	guiloader
PORTVERSION=	2.10.0
CATEGORIES=	devel gnome
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	crow-designer

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A C++ binding to the GuiLoader library

USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	atk glib20 gtk20 pango
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/${PORTNAME}/Makefile.in

.include <bsd.port.mk>
