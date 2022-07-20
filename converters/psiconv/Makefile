PORTNAME=	psiconv
PORTVERSION=	0.9.9
CATEGORIES=	converters devel
MASTER_SITES=	http://www.frodo.looijaard.name/system/files/software/psiconv/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Conversion utility to convert Psion 5(MX) files into other formats

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-imagemagick=no
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
