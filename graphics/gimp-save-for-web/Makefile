# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gimp-save-for-web
PORTVERSION=	0.29.3
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	GIMP Save For Web plugin

LIB_DEPENDS=	libgimp-2.0.so:${PORTSDIR}/graphics/gimp-app
BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USES=		gettext gmake pkgconfig pathfix perl5 tar:bzip2
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_GNOME=	intltool

post-patch:
	@${REINPLACE_CMD} -e 's|GMSGFMT = @GMSGFMT@|GMSGFMT = @MSGFMT@|g' ${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
