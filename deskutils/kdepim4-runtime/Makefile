# New ports collection Makefile for:	kdepimp4
# Date created:				2008-31-05
# Whom:					miwi
#
# $FreeBSD$

PORTNAME=	kdepim-runtime
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries for KDE-PIM applications

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

CONFLICTS=	kdepimlibs-4.3.[1-4]

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	pimlibs kdeprefix kdehier sharedmime automoc4
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus qt3support designer network svg qtestlib \
		xml gui qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

post-patch:
	${GREP} -H -r "#include <q" ${WRKSRC} | ${CUT} -d: -f1 | uniq | \
		${XARGS} ${REINPLACE_CMD} -f ${FILESDIR}/qt3to4headers.txt

pre-configure:
	#respect prefix
	${FIND} ${WRKSRC} -type f -name CMakeLists.txt | ${XARGS} \
	${REINPLACE_CMD} -e '/^install/s,KDE4_DBUS_INTERFACES_DIR,DBUS_INTERFACES_INSTALL_DIR,g'

.include <bsd.port.mk>
