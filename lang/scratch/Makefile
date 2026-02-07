PORTNAME=	scratch
PORTVERSION=	1.4.0.7
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://download.scratch.mit.edu/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	takeshi.mutoh@gmail.com
COMMENT=	Scratch programing language
WWW=		https://scratch.mit.edu/

LICENSE=	CC-BY-SA-3.0 GPLv2 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	v4l_compat>=1.0.20100321:multimedia/v4l_compat
LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
RUN_DEPENDS=	squeak:lang/squeak

USES=		gnome pkgconfig
USE_GNOME=	pango

DESKTOP_ENTRIES=	"Scratch" \
			"${COMMENT}" \
			"${DATADIR}/icons/128x128/scratch.png" \
			"scratch" \
			"Development;Education;" \
			false
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.src

SC_DIR=		${PREFIX}/share/scratch

post-patch:
	${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/scratch

do-install:
	@${MKDIR} ${STAGEDIR}${SC_DIR}/Plugins
.for p in Unicode Scratch Camera
	${INSTALL_LIB} ${WRKSRC}/Plugins/so.${p}Plugin ${STAGEDIR}${SC_DIR}/Plugins/
.endfor
.for f in Help locale Media Projects
	@cd ${WRKSRC}/$f && ${COPYTREE_SHARE} . ${STAGEDIR}${SC_DIR}/$f
.endfor
.for f in Scratch.image Scratch.ini
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${SC_DIR}/$f
.endfor
	@cd ${WRKSRC}/src/icons && ${COPYTREE_SHARE} . ${STAGEDIR}${SC_DIR}/icons
	${INSTALL_SCRIPT} ${WRKSRC}/src/scratch ${STAGEDIR}${PREFIX}/bin/scratch
	${INSTALL_MAN} ${WRKSRC}/src/man/scratch.1.gz ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/src/scratch.desktop ${STAGEDIR}${PREFIX}/share/applications/scratch.desktop

.include <bsd.port.mk>
