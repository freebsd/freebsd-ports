# Created by: sada

PORTNAME=	mikachan
PORTVERSION=	9.1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://mikachan.sourceforge.jp/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	ver${PORTVERSION}
EXTRACT_SUFX=	.lzh
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	TsurutaniNaoki@gmail.com
COMMENT=	Handwritten Japanese TrueType fonts by Mika-chan

# Converted from NO_CDROM
LICENSE=	mikachan
LICENSE_NAME=	mikachan
LICENSE_TEXT=	Do not sell distfile
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

EXTRACT_DEPENDS=	lha:archivers/lha

USES=		fonts:fc
FONTNAME=	TTF
EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	pq
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/mika.ttf
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	pkg-install
SUB_LIST=	DIRFILE="${DATADIR}/fonts.dir"
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
PLIST_FILES=	%%DATADIR%%/fonts.dir \
		%%DATADIR%%/mika.ttf \
		%%FONTSDIR%%/mika.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} \
	    ${WRKSRC}/mika.ttf ${FILESDIR}/fonts.dir \
	    ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && \
	    ${LN} -s ../../../${DATADIR_REL}/*.ttf .

.include <bsd.port.mk>
