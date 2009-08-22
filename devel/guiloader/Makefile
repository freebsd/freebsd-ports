# New ports collection makefile for:	guiloader
# Date created:		11 May 2007
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	guiloader
PORTVERSION=	2.15.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	SF/crow-designer/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-performance and compact GuiXml loader library

USE_BZIP2=	yes
USE_GNOME=	gnomehack gtk20
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-hidden-visibility
USE_LDCONFIG=	yes

.include <bsd.port.mk>
