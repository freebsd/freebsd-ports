PORTNAME=	i3lock
PORTVERSION=	2.13
PORTREVISION=	1
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

MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" CC="${CC}" \
		MANDIR="${MANPREFIX}/man"

PLIST_FILES=	bin/i3lock \
		man/man1/i3lock.1.gz \
		etc/pam.d/i3lock

SUB_FILES=	i3lock.pam

USES=		gmake iconv localbase pkgconfig tar:bzip2 xorg
LDFLAGS+=	${ICONV_LIB}
USE_XORG=	x11 xcb xt xorgproto xext
USE_CSTD=	c99
GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	i3lock-color

PORTDOCS=	CHANGELOG README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/i3lock
	@${RM} ${STAGEDIR}${PREFIX}/etc/pam.d/i3lock
	@${INSTALL_DATA} ${WRKDIR}/i3lock.pam ${STAGEDIR}${PREFIX}/etc/pam.d/i3lock

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
