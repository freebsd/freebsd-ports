# New ports collection makefile for:	gimp-save-for-web
# Date created:		2009-11-25
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	gimp-save-for-web
PORTVERSION=	0.29.3
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/

MAINTAINER=	magik@roorback.net
COMMENT=	GIMP Save For Web plugin

LIB_DEPENDS=	gimp-2.0:${PORTSDIR}/graphics/gimp-app
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intltool

post-patch:
	@${REINPLACE_CMD} -e 's|GMSGFMT = @GMSGFMT@|GMSGFMT = @MSGFMT@|g' ${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
