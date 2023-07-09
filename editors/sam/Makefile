PORTNAME=	sam
DISTVERSION=	g20230103
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	flo@purplekraken.com
COMMENT=	Unix port of the Sam text editor from Plan 9
WWW=		https://github.com/deadpixi/sam

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		localbase:ldflags xorg

USE_GITHUB=	yes
GH_ACCOUNT=	deadpixi
GH_PROJECT=	sam
GH_TAGNAME=	5d8acb3

USE_XORG=	x11 xft xi xt

# Some random build system fixes
MAKE_JOBS_UNSAFE=yes
CFLAGS+=	-I${LOCALBASE}/include/freetype2

do-configure:
	${SED} -e 's/LDFLAGS=/LDFLAGS?=/' -e 's/CC=/CC?=/' \
	    ${WRKSRC}/config.mk.def >${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sam/sam ${STAGEDIR}${PREFIX}/bin
	${RLN} ${STAGEDIR}${PREFIX}/bin/sam ${STAGEDIR}${PREFIX}/bin/B
	${INSTALL_PROGRAM} ${WRKSRC}/samterm/samterm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ssam/ssam.sh ${STAGEDIR}${PREFIX}/bin/ssam
	${INSTALL_MAN} ${WRKSRC}/doc/sam.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man1/sam.1 ${STAGEDIR}${PREFIX}/share/man/man1/B.1
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man1/sam.1 ${STAGEDIR}${PREFIX}/share/man/man1/samterm.1
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man1/sam.1 ${STAGEDIR}${PREFIX}/share/man/man1/rsam.1
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man1/sam.1 ${STAGEDIR}${PREFIX}/share/man/man1/sam.save.1
	${INSTALL_MAN} ${WRKSRC}/doc/samrc.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
