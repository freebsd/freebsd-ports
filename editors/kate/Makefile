# New ports collection makefile for:	kate
# Date created:				Tue  9 Aug 2011, 00:58:45
# Whom:					fluffy@
#
# $FreeBSD$
#

PORTNAME=	kate
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic editor framework for the KDE system

CONFLICTS=	kdebase-4.[0-6].* kdelibs-4.[0-6].* kdesdk-4.[0-6].*

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4 sharedmime
KDE4_BUILDENV=	yes
USE_PERL5_BUILD=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui qt3support script sql xml \
		moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

MAN1=	kate.1

post-patch:
	# Prevent updating MIME during build.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/kate/plugins/snippets_tng/CMakeLists.txt

post-install:
	@-update-mime-database ${KDE4_PREFIX}/share/mime

.include <bsd.port.mk>
