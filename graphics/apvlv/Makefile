# New ports collection makefile for: apvlv
# Date created:                03 May 2010
# Whom:                        Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	apvlv
PORTVERSION=	0.0.9.6
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jupengfei@gmail.com
COMMENT=	Apvlv is a PDF Viewer Under Linux and its behaviour like Vim

LIB_DEPENDS=	poppler-glib.4:${PORTSDIR}/graphics/poppler-gtk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-sysconfdir=${PREFIX}/etc

MAN1=		apvlv.1

.include <bsd.port.mk>
