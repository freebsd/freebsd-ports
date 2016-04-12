# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	giftool
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/graphics/convert/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for GIF89a transparent option and interlace mode

NO_CDROM=	Shareware

NO_WRKSUBDIR=	yes
ALL_TARGET=	giftool
MAKE_ARGS=	CFLAGS="${CFLAGS}"
USES=		tar:tgz

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
