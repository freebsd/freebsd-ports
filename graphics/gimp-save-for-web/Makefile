# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gimp-save-for-web
PORTVERSION=	0.29.3
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GIMP Save For Web plugin

LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp-app
BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gettext gmake perl5 pkgconfig tar:bzip2
USE_PERL5=	build
USE_GNOME=	intltool

.include <bsd.port.mk>
