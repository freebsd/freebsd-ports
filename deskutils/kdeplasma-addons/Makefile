# New ports collection makefile for:	kdeplasmoids
# Date created:		2008-06-29
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kdeplasma-addons
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@freebsd.org
COMMENT=	Extra plasmoids for KDE4

BUILD_DEPENDS=	eigen>=2.0.b3:${PORTSDIR}/math/eigen2
LIB_DEPENDS=	marblewidget.5:${PORTSDIR}/misc/kdeedu4 \
		kipi.6:${PORTSDIR}/graphics/kdegraphics4

USE_KDE4=	kdelibs pimlibs workspace kdeprefix kdehier automoc4 sharedmime
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus qt3support  webkit \
		designer network svg qtestlib xml \
		qmake_build moc_build rcc_build uic_build

MAKE_JOBS_SAFE=	yes

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${GREP} -H -r "#include <q" ${WRKSRC}/.. | ${CUT} -d: -f1 | uniq | \
		${XARGS} ${REINPLACE_CMD} -f ${FILESDIR}/qt3to4headers.txt

pre-configure:
	#respect prefix, don't update mime when installing
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/d; /SharedMimeInfo/d' \
		-e '/^set/s,DBUS_INTERFACES_INSTALL_DIR,KDE4_DBUS_INTERFACES_DIR,g' \
		${WRKSRC}/../applets/lancelot/app/src/CMakeLists.txt

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
