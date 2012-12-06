# Created by: Diego DepaolI <trebestie@gmail.com>
# $FreeBSD$

PORTNAME=	texworks
PORTVERSION=	0.2.2
PORTREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Simple TeX front-end program

BUILD_DEPENDS=	hunspell:${PORTSDIR}/textproc/hunspell
LIB_DEPENDS=	poppler-qt4:${PORTSDIR}/graphics/poppler-qt4

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_QT4=	qmake_build gui corelib rcc_build moc_build uic_build \
		dbus xml

MAKE_ENV+=	QTDIR=${QT_PREFIX}

DESKTOP_ENTRIES="TexWorks" \
		"Lowering the entry barrier to the TeX world" \
		"TeXworks.png" \
		"texworks" \
		"Application;Utility;" \
		false
PLIST_FILES=	bin/texworks \
		share/pixmaps/TeXworks.png

post-patch:
	@${REINPLACE_CMD} -e 's|\/usr\/share|\${LOCALBASE}\/share|g' ${WRKSRC}/src/TWUtils.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} TeXworks.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texworks ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/res/images/TeXworks.png ${PREFIX}/share/pixmaps/TeXworks.png

.include <bsd.port.mk>
