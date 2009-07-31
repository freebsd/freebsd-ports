# New ports collection makefile for:	kdeplasmoids
# Date created:		2008-06-29
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kdeplasma-addons
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@freebsd.org
COMMENT=	Extra plasmoids for KDE4

USE_KDE4=	kdelibs pimlibs workspace kdeprefix kdehier automoc4 sharedmime
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	opengl webkit xml network \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_UNSAFE=	yes

post-extract:
	${MKDIR} ${WRKSRC}

pre-configure:
	#respect prefix, don't update mime when installing
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/d; /SharedMimeInfo/d' \
		-e '/^set/s,DBUS_INTERFACES_INSTALL_DIR,KDE4_DBUS_INTERFACES_DIR,g' \
		${WRKSRC}/../applets/lancelot/app/src/CMakeLists.txt

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
