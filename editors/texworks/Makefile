# Created by: Diego Depaoli <trebestie@gmail.com>
# $FreeBSD$

PORTNAME=	texworks
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-r${VCS_REVISION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Simple TeX front-end program

LICENSE=	GPLv2

BUILD_DEPENDS=	hunspell:${PORTSDIR}/textproc/hunspell
LIB_DEPENDS=	poppler-qt4:${PORTSDIR}/graphics/poppler-qt4

USE_PKGCONFIG=	build
USE_QT4=	qmake_build gui corelib rcc_build moc_build uic_build \
		dbus xml
QMAKE_ARGS=	INSTALL_PREFIX=${PREFIX} \
		DATA_DIR=${DATADIR} \
		DOCS_DIR=${DOCSDIR} \
		ICON_DIR=${PREFIX}/share/pixmaps \
		DESKTOP_DIR=${PREFIX}/share/applications \
		MAN_DIR=${MAN1PREFIX}/man/man1 \
		TW_DICPATH=${LOCALBASE}/hunspell \
		TW_HELPPATH=${DOCSDIR}
MAKE_JOBS_SAFE=	yes

VCS_REVISION=	1004
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DESKTOP_ENTRIES="TexWorks" \
		"Lowering the entry barrier to the TeX world" \
		"TeXworks" \
		"${PORTNAME}" \
		"Utility;" \
		false

MAN1=		texworks.1
PLIST_FILES=	bin/texworks \
		share/pixmaps/TeXworks.png
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/zlib/d; s|COPYING ||' ${WRKSRC}/TeXworks.pro
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/INSTALLS/s|documentation manual ||' \
		${WRKSRC}/TeXworks.pro
.endif
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|' \
		${WRKSRC}/src/TWUtils.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKE_ARGS} TeXworks.pro

.include <bsd.port.mk>
