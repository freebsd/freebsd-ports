PORTNAME=	modplug-tools
PORTVERSION=	0.5.6
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command line mod music players using libmodplug

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libao.so:audio/libao \
		libmodplug.so:audio/libmodplug

USES=		cmake:noninja localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	alexmyczko
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/modplug123 \
		share/man/man1/modplug123.1.gz

.include <bsd.port.mk>
