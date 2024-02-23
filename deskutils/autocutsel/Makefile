PORTNAME=	autocutsel
PORTVERSION=	0.10.1
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	john@jnielsen.net
COMMENT=	Synchronizes the two copy/paste buffers used by X applications
WWW=		https://www.nongnu.org/autocutsel/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool xorg
USE_GITHUB=	yes
GH_ACCOUNT=	sigmike
USE_XORG=	ice sm x11 xaw xext xmu xt

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/autocutsel \
		bin/cutsel \
		share/man/man1/autocutsel.1.gz \
		share/man/man1/cutsel.1.gz

post-configure:
	@${REINPLACE_CMD} -e 's|-I\.|-I/usr/local/include|g' ${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
