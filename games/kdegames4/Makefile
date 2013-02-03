# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdegames
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Games for KDE 4

LIB_DEPENDS=	ggzcore.9:${PORTSDIR}/games/ggz-client-libs \
		qca.2:${PORTSDIR}/devel/qca \
		qhull.5:${PORTSDIR}/math/qhull5 \
		sndfile.1:${PORTSDIR}/audio/libsndfile

LATEST_LINK=	${PORTNAME}4

USE_GL=		glu
USE_KDE4=	kdehier kdelibs kdeprefix sharedmime automoc4
KDE4_BUILDENV=	yes
USE_OPENAL=	al
USE_QT4=	dbus gui network opengl qt3support script svg xml \
		moc_build qmake_build rcc_build uic_build
USE_XZ=		yes
CMAKE_ARGS+=	-DBUILD_kajongg:BOOL=FALSE
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	KAJONGG

KAJONGG_DESC=	Install the classical Mah Jongg for four players

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKAJONGG}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kajongg:${PORTSDIR}/games/kajongg
.endif

post-patch:
	# Prevent updating MIME during build.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d' \
		${WRKSRC}/palapeli/mime/CMakeLists.txt

post-install:
	@-update-mime-database ${KDE4_PREFIX}/share/mime

.include <bsd.port.mk>
