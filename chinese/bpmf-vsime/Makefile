PORTNAME=	bpmf-vsime
PORTVERSION=	1.500
CATEGORIES=	chinese
MASTER_SITES=	https://github.com/ButTaiwan/bpmfvs/releases/download/v${PORTVERSION}/
DISTNAME=	Bpmf_VSIME
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Bopomofo IVS reading selection tool
WWW=		https://github.com/ButTaiwan/bpmfvs

LICENSE=	APACHE20 CC-BY-ND-3.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-2.0.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT.txt

RUN_DEPENDS=	${LOCALBASE}/share/fonts/bpmf-zihikai/BpmfZihiKaiStd-Regular.ttf:x11-fonts/bpmf-zihikai

USES=		zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

PORTDATA=	index.html ime.js jquery.min.js poyin_db.js tzdic zhdicui.js \
		zhuivsdic.js zihaidic.css

# Render with the font installed by x11-fonts/bpmf-zihikai instead of the
# copy bundled in the distfile, which is not installed.
post-patch:
	@${REINPLACE_CMD} -e "s|url('BpmfZihiKaiStd-Regular.ttf')|url('../fonts/bpmf-zihikai/BpmfZihiKaiStd-Regular.ttf')|" \
		${WRKSRC}/index.html ${WRKSRC}/zihaidic.css

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NOTICE.txt ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
