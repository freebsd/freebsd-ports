# New ports collection makefile for:	albumshaper
# Date created:				17 Jul 2007
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	albumshaper
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A drag-n-drop hierarchal photo album creation

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_BZIP2=	yes
USE_ICONV=	yes
USE_QT_VER=	3
USE_GNOME=	libxml2 libxslt

WRKSRC=		${WRKDIR}/${DISTNAME}_src

CONFIGURE_ENV+=	QTDIR=${QT_PREFIX} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
MAKE_ENV+=	QTDIR=${QT_PREFIX} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

DESKTOP_ENTRIES=	"AlbumShaper" \
			"A drag-n-drop hierarchal photo album creation" \
			"${DATADIR}/images/miscImages/as32.png" \
			"AlbumShaper" \
			"Qt;KDE;Graphics;" \
			"false"

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

MYDISTDOCS=	AlbumShaper.doc install packageHowTo.txt readme.txt \
		readme_precompiled.txt docs/bugs.txt docs/copying.txt

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/AlbumShaper.pro
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e '/INSTALLS\ +=\ translations/d' \
		${WRKSRC}/AlbumShaper.pro
.endif

pre-build:
	( cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		qmake AlbumShaper.pro )

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${MYDISTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
