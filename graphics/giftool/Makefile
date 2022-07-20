PORTNAME=	giftool
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/graphics/convert/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for GIF89a transparent option and interlace mode

# Converted from NO_CDROM
LICENSE=	giftool
LICENSE_NAME=	giftool
LICENSE_TEXT=	Shareware
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

NO_WRKSUBDIR=	yes
ALL_TARGET=	giftool
MAKE_ARGS=	CFLAGS="${CFLAGS}"
USES=		tar:tgz

CONFLICTS_INSTALL=	giflib

OPTIONS_DEFINE=	RETVALUE MALLOCSIZE DOCS
OPTIONS_DEFAULT=	RETVALUE MALLOCSIZE
RETVALUE_DESC=	Return value patch
MALLOCSIZE_DESC=	Improve malloc size

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	COPYRIGHT README

RETVALUE_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-aa
MALLOCSIZE_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-ab

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/giftool ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
