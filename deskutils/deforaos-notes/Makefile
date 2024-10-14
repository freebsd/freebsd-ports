PORTNAME=	notes
PORTVERSION=	0.2.1
CATEGORIES=	deskutils
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Notes/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Notes-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop notes
WWW=		https://www.defora.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libDesktop.so:x11/deforaos-libdesktop \
		libSystem.so:devel/deforaos-libsystem

USES=		desktop-file-utils gnome pkgconfig xorg
USE_GNOME=	gtk30
USE_XORG=	x11
MAKE_ARGS+=	PREFIX=${PREFIX}

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_SUB=		yes
DOCS_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
NLS_USES=		gettext

post-patch:
	${REINPLACE_CMD} 's|-Wl,-pie||g' \
		${WRKSRC}/src/Makefile

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|= data doc|= data|' \
		${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|po src tools|src tools|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/notes \
		${STAGEDIR}${PREFIX}/lib/libNotes.so.0.0

.include <bsd.port.mk>
