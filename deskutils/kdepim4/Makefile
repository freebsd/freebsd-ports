# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdepim
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries for KDE-PIM applications

LIB_DEPENDS=	gpgme.19:${PORTSDIR}/security/gpgme \
		assuan.0:${PORTSDIR}/security/libassuan \
		sasl2:${PORTSDIR}/security/cyrus-sasl2 \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		grantlee_gui.0:${PORTSDIR}/devel/grantlee \
		clucene-core:${PORTSDIR}/textproc/clucene
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	${KDE4_PREFIX}/bin/accountwizard:${PORTSDIR}/deskutils/kdepim4-runtime

LATEST_LINK=	${PORTNAME}4
CONFLICTS_INSTALL=	kdepim-4.4.*

USE_XZ=	yes
USE_GNOME=	libxml2
USE_ICONV=	yes
USE_KDE4=	kdehier kdelibs kdeprefix pimlibs \
		akonadi automoc4 ontologies soprano strigi
KDE4_BUILDENV=	yes
USE_OPENLDAP=	yes
USE_QT4=	dbus designer gui network \
		qt3support script sql webkit xml \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	x11 xscrnsaver
CMAKE_ARGS+=	-DKDEPIM_BUILD_MOBILE:BOOL=FALSE
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kabcclient.1

.include <bsd.port.mk>
