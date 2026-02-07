PORTNAME=	xwax
DISTVERSION=	1.9
CATEGORIES=	audio
MASTER_SITES=	https://www.xwax.co.uk/releases/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open-source vinyl emulation software
WWW=		https://wiki.xwax.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack
RUN_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

USES=		compiler:c++11-lang gmake iconv localbase:ldflags sdl shebangfix
USE_SDL=	sdl ttf

SHEBANG_FILES=	scan

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-jack \
		--enable-oss

LDFLAGS+=	-liconv -lm

PLIST_FILES=	bin/xwax \
		libexec/xwax-import \
		libexec/xwax-scan \
		share/man/man1/xwax.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/|${LOCALBASE}/|' ${WRKSRC}/interface.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xwax

.include <bsd.port.mk>
