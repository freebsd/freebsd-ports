# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	nagaina
PORTVERSION=	0.1.2
DISTVERSIONSUFFIX=	-sources
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Notes-taking application based on Qt4

LICENSE=	GPLv2

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GNOME=	glib20
USE_QT4=	corelib gui xml moc_build qmake_build rcc_build uic_build
USE_XORG=	ice sm x11 xau xdmcp xext xrender
MAKE_JOBS_SAFE=	yes

PORTDOCS=	CHANGELOG TODO
PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES=	"Nagaina" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
			"${PORTNAME}" \
			"Qt;Office;Utility;" \
			"false"

.include <bsd.port.options.mk>

do-configure:
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

post-install:
	(cd ${WRKSRC}/bin \
		&& ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin)
	(cd ${WRKSRC}/images \
		&& ${INSTALL_DATA} ${PORTNAME}.png ${PREFIX}/share/pixmaps)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
