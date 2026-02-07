PORTNAME=	opencity
PORTVERSION=	0.0.6.5
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Stable/${PORTVERSION:C/^([0-9]+\.[0-9]+\.[0-9]+)\..*$/\1/}/
DISTNAME=	${PORTNAME}-${PORTVERSION}stable

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free 3D city simulator
WWW=		http://www.opencity.info/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES=		compiler:c11 gl gmake pkgconfig sdl tar:bzip2
USE_SDL=	sdl mixer image net
USE_GL=		gl glu
INSTALL_TARGET=	install-strip

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
