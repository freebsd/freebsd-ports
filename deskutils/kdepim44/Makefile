# New ports collection Makefile for:	kdepimp4
# Date created:				2008-31-05
# Whom:					miwi
#
# $FreeBSD$

PORTNAME=	kdepim
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries for KDE-PIM applications

BUILD_DEPENDS=	libassuan-1>=1.0.5:${PORTSDIR}/security/libassuan-1
LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme \
		sasl2:${PORTSDIR}/security/cyrus-sasl2 \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		qca.2:${PORTSDIR}/devel/qca

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdelibs pimlibs pimruntime \
		akonadi kdeprefix kdehier automoc4 oxygen
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus qt3support designer network svg qtestlib \
		qmake_build moc_build rcc_build uic_build
USE_OPENLDAP=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kabcclient.1

#OPTIONS=	KITCHENSYNC "PIM synchronization utility" off

.include <bsd.port.options.mk>

# kitchensync is disabled in KDE 4.2
# .if defined(WITH_KITCHENSYNC)
# LIB_DEPENDS+=	opensync.1:${PORTSDIR}/devel/libopensync
# PLIST_SUB+=	KITCHENSYNC=""
# .else
# CMAKE_ARGS+=	-DWITH_Opensync:BOOL=off
# PLIST_SUB+=	KITCHENSYNC="@comment "
# .endif

pre-configure:
# respect prefix
	${FIND} ${PATCH_WRKSRC} -type f -name CMakeLists.txt | ${XARGS} \
	${REINPLACE_CMD} -e '/DESTINATION/s,KDE4_DBUS_INTERFACES_DIR,DBUS_INTERFACES_INSTALL_DIR,g'

.include <bsd.port.mk>
