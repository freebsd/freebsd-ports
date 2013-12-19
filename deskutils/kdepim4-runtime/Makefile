# Created by: miwi
# $FreeBSD$

PORTNAME=	kdepim-runtime
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries for KDE-PIM applications

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libkgapi.so:${PORTSDIR}/devel/libkgapi \
		libkolab.so:${PORTSDIR}/devel/libkolab
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

CONFLICTS=		akonadi-google-0.*
CONFLICTS_INSTALL=	kdepim-runtime44-4.*

USE_XZ=		yes
USE_GNOME=	libxml2
USE_KDE4=	kdehier kdelibs kdeprefix pimlibs nepomuk-core \
		akonadi automoc4 ontologies sharedmime soprano strigi
USES=		cmake:outsource
USE_QT4=	corelib dbus declarative designer_build gui network qtestlib \
		script xml xmlpatterns \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null
CMAKE_ARGS=	-DKDEPIM_MOBILE_UI:BOOL=OFF

NO_STAGE=	yes
post-patch:
	${GREP} -H -r "#include <q" ${WRKSRC} | ${CUT} -d: -f1 | uniq | \
		${XARGS} ${REINPLACE_CMD} -f ${FILESDIR}/qt3to4headers.txt
# Prevent updating MIME during build.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d' \
		${PATCH_WRKSRC}/CMakeLists.txt \
		${PATCH_WRKSRC}/accountwizard/CMakeLists.txt

.include <bsd.port.mk>
