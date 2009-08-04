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

BUILD_DEPENDS=	libassuan>=1.0.4:${PORTSDIR}/security/libassuan
LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme \
		sasl2:${PORTSDIR}/security/cyrus-sasl2 \
		boost_python:${PORTSDIR}/devel/boost-python-libs \
		qca.2:${PORTSDIR}/devel/qca

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdelibs kdeexp pimlibs runtime akonadi kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus qt3support designer network svg qtestlib \
		xml gui qmake_build moc_build rcc_build uic_build
USE_OPENLDAP=	yes
MAKE_JOBS_SAFE=	yes

#fix build when kdepim3 is here
CMAKE_ARGS+=	-DGPGME_LIBRARY_DIR:PATH="${KDE4_PREFIX}/lib"

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${GREP} -H -r "#include <q" ${WRKSRC}/.. | ${CUT} -d: -f1 | uniq | \
		${XARGS} ${REINPLACE_CMD} -f ${FILESDIR}/qt3to4headers.txt

pre-configure:
	#respect prefix
	${FIND} ${WRKSRC}/.. -type f -name CMakeLists.txt | ${XARGS} \
	${REINPLACE_CMD} -e '/^install/s,KDE4_DBUS_INTERFACES_DIR,DBUS_INTERFACES_INSTALL_DIR,g'
	@${REINPLACE_CMD} -e 's|add_subdirectory( kolabproxy )||' \
		${WRKSRC}/../resources/CMakeLists.txt

.include <bsd.port.mk>
