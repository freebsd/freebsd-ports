# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gimp-save-for-web
PORTVERSION=	0.29.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	GIMP Save For Web plugin

LIB_DEPENDS=	gimp-2.0:${PORTSDIR}/graphics/gimp-app
BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack intltool

post-patch:
	@${REINPLACE_CMD} -e 's|GMSGFMT = @GMSGFMT@|GMSGFMT = @MSGFMT@|g' ${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
