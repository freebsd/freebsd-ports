# New ports collection Makefile for:	kdepimp4
# Date created:				2008-31-05
# Whom:					miwi
#
# $FreeBSD$

PORTNAME=	kdepim
PORTVERSION=	${KDEPIM4_VERSION}
PORTREVISION=	2
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEPIM4_BRANCH}/kdepim-${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries for KDE-PIM applications

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml

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

#cannot be built with assuan2
CMAKE_ARGS+=	-DWITH_Assuan:BOOL=off

pre-configure:
# respect prefix
	${FIND} ${PATCH_WRKSRC} -type f -name CMakeLists.txt | ${XARGS} \
	${REINPLACE_CMD} -e '/DESTINATION/s,KDE4_DBUS_INTERFACES_DIR,DBUS_INTERFACES_INSTALL_DIR,g'

.include <bsd.port.mk>
