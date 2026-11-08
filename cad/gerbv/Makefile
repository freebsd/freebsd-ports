PORTNAME=	gerbv
DISTVERSIONPREFIX=	v
DISTVERSION=	2.13.0
CATEGORIES=	cad
MASTER_SITES=	GH

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Gerber file viewer
WWW=		https://gerbv.github.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext \
		gnome libtool localbase pkgconfig
CPE_VENDOR=	gerbv_project
USE_GITHUB=	yes
USE_GNOME=	cairo gtk20
USE_LDCONFIG=	yes


CONFIGURE_ENV=	ac_aux_dir="."
CFLAGS+=	-fcommon

PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	(cd ${WRKSRC}/desktop && ${INSTALL_DATA} gerbv.desktop \
		${STAGEDIR}${DESKTOPDIR})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	(cd ${WRKSRC}/desktop && ${INSTALL_DATA} gerbv.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps)
.for i in 16 22 24 32 48
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	(cd ${WRKSRC}/desktop && ${INSTALL_DATA} gerbv-${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/gerbv.png)
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.fig *.txt \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/PNG-print
	(cd ${WRKSRC}/doc/PNG-print && ${INSTALL_DATA} *.jpg *.txt \
		${STAGEDIR}${DOCSDIR}/PNG-print)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/eagle
	(cd ${WRKSRC}/doc/eagle && ${INSTALL_DATA} *.pl *.txt \
		${STAGEDIR}${DOCSDIR}/eagle)

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/example && ${FIND} . \
		! \( -name "*Makefile*" -or -name ".cvsignore" \) \
		| ${CPIO} --quiet -pdm -L -R ${SHAREOWN}:${SHAREGRP} \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
