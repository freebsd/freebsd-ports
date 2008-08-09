# New ports collection Makefile for:	kdepimp4
# Date created:				2008-31-05
# Whom:					miwi
#
# $FreeBSD$

PORTNAME=	kdepim
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries for KDE-PIM applications

BUILD_DEPENDS=	libassuan>=1.0.4:${PORTSDIR}/security/libassuan
LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme \
		sasl2:${PORTSDIR}/security/cyrus-sasl2 \
		boost_python:${PORTSDIR}/devel/boost-python \
		mal.1:${PORTSDIR}/palm/libmal \
		pisock.9:${PORTSDIR}/palm/pilot-link

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdelibs pimlibs kdebase akonadi kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl moc rcc uic dbus qt3support designer network svg qtestlib
USE_OPENLDAP=	yes

OPTIONS=	GNOKII "KAdressbook import/export for Nokia phones" off \
		KITCHENSYNC "PIM synchronization utility" off

.include <bsd.port.pre.mk>

.if defined(WITH_GNOKII)
LIB_DEPENDS+=	gnokii:${PORTSDIR}/comms/gnokii
PLIST_SUB+=	GNOKII=""
.else
CMAKE_ARGS+=	-DWITH_GNOKII:BOOL=off
PLIST_SUB+=	GNOKII="@comment "
.endif

.if defined(WITH_KITCHENSYNC)
LIB_DEPENDS+=	opensync.1:${PORTSDIR}/devel/libopensync
PLIST_SUB+=	KITCHENSYNC=""
.else
CMAKE_ARGS+=	-DWITH_Opensync:BOOL=off
PLIST_SUB+=	KITCHENSYNC="@comment "
.endif

post-extract:
	${MKDIR} ${WRKSRC}

.include <bsd.port.post.mk>
