# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	modplug-tools
PORTVERSION=	0.5.4
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command line mod music players using libmodplug

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libao.so:audio/libao \
		libmodplug.so:audio/libmodplug

USES=		localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	alexmyczko
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/modplug123 \
		bin/modplugplay \
		share/man/man1/modplug123.1.gz \
		share/man/man1/modplugplay.1.gz

post-install:
	${MKDIR} ${STAGEDIR}${MANPREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/modplug*.1 \
		${STAGEDIR}${MANPREFIX}/share/man/man1

.include <bsd.port.mk>
