PORTNAME=	ssocr
DISTVERSION=	2.24.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~auerswal/ssocr/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	CLI to recognize digits of a seven segment display
WWW=		https://www.unix-ag.uni-kl.de/~auerswal/ssocr/ \
		https://github.com/auerswal/ssocr

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		gmake pkgconfig tar:bzip2

PLIST_FILES=	bin/ssocr \
		share/man/man1/ssocr.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
