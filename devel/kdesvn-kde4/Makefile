# New ports collection makefile for:	kdesvn
# Date created:				08 April 2006
# Whom:					Yuan Jue <yuanjue@yuanjue.net>
#
# $FreeBSD$

PORTNAME=	kdesvn
DISTVERSION=	1.5.3
CATEGORIES=	devel kde
MASTER_SITES=	http://kdesvn.alwins-world.de/downloads/
PKGNAMESUFFIX=	-kde4

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	KDE frontend for Subversion

LIB_DEPENDS=	svn_client-1:${PORTSDIR}/devel/subversion

LICENSE=	GPLv2

CONFLICTS=	qsvn-[0-9]*

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS+=	-DSUBVERSION_INCLUDE_DIR=${LOCALBASE}/include/subversion-1
USE_GETTEXT=	yes
USE_KDE4=	kdelibs kdeprefix automoc4
USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui xml network dbus svg qt3support sql \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

MAN1=		kdesvn.1 kdesvnaskpass.1

post-patch:
	${RM} ${WRKSRC}/src/kiosvn/svn*.protocol
.if defined(NOPORTDOCS)
	${ECHO} "ADD_SUBDIRECTORY(man)" > ${WRKSRC}/doc/CMakeLists.txt
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
