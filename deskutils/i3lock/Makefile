PORTNAME=	i3lock
PORTVERSION=	2.16
CATEGORIES=	deskutils x11
MASTER_SITES=	http://i3wm.org/${PORTNAME}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Slightly improved screen locker based on slock
WWW=		https://i3wm.org/i3lock/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-image.so:x11/xcb-util-image \
		libev.so:devel/libev \
		libxkbfile.so:x11/libxkbfile \
		libxkbcommon.so:x11/libxkbcommon \
		libxcb-util.so:x11/xcb-util \
		libxcb-xrm.so:x11/xcb-util-xrm

RUN_DEPENDS=	unix-selfauth-helper>0:security/unix-selfauth-helper

PLIST_FILES=	bin/i3lock \
		share/man/man1/i3lock.1.gz \
		etc/pam.d/i3lock

USES=		iconv localbase meson pkgconfig tar:xz xorg
LDFLAGS+=	${ICONV_LIB}
USE_XORG=	x11 xcb xt xorgproto xext
USE_CSTD=	c99

CONFLICTS_INSTALL=	i3lock-color
ALL_TARGET=

PORTDOCS=	CHANGELOG README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/etc/pam.d/i3lock
	@${LN} -s ${LOCALBASE}/etc/pam.d/unix-selfauth \
		${STAGEDIR}${PREFIX}/etc/pam.d/i3lock

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
