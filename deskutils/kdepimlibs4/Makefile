# New ports collection Makefile for:	kdepimplibs
# Date created:				2008-01-20
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kdepimlibs
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries for KDE-PIM applications

LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme \
		sasl2:${PORTSDIR}/security/cyrus-sasl2 \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		ical.44:${PORTSDIR}/devel/libical

CONFLICTS=	kdepim-runtime-4.3.[1-4]

USE_KDE4=	kdelibs akonadi kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus qt3support \
		designer network svg qtestlib help \
		qmake_build moc_build rcc_build uic_build
USE_OPENLDAP=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libgpgme-pth.so)
PLIST_SUB+=	WITH_PTH=''
.else
PLIST_SUB+=	WITH_PTH='@comment '
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake/modules/*.cmake
	${REINPLACE_CMD} -e '/find_package/s,PATHS,PATHS ${KDE4_PREFIX}/lib/cmake/Akonadi,' \
		${PATCH_WRKSRC}/cmake/modules/FindAkonadi.cmake
	${REINPLACE_CMD} -e 's|%%KDE4_PREFIX%%|${KDE4_PREFIX}|g' \
		${PATCH_WRKSRC}/cmake/modules/FindQGpgme.cmake

.include <bsd.port.post.mk>
