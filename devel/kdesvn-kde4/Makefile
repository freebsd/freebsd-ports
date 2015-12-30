# Created by: Yuan Jue <yuanjue@yuanjue.net>
# $FreeBSD$

PORTNAME=	kdesvn
DISTVERSION=	1.6.0
PORTREVISION=	4
CATEGORIES=	devel kde
MASTER_SITES=	http://box.alwins-world.de/owncloud/index.php/s/3e6f4c2273b329c185ff25824277bf42/download?path=%2F1.6.0&files=kdesvn-1.6.0.tar.bz2&dummy=

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	KDE frontend for Subversion

LIB_DEPENDS=	libsvn_client-1.so:${PORTSDIR}/devel/subversion

LICENSE=	GPLv2

CONFLICTS=	qsvn-[0-9]*

FETCH_ARGS=	-Fpr -o ${DISTFILES}

USES=		cmake tar:bzip2
CMAKE_ARGS+=	-DSUBVERSION_INCLUDE_DIR=${LOCALBASE}/include/subversion-1
USE_KDE4=	kdelibs kdeprefix automoc4
USE_LDCONFIG=	yes
USE_QT4=	corelib gui xml network dbus svg qt3support sql \
		qmake_build moc_build rcc_build uic_build linguist_build

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${RM} ${WRKSRC}/src/kiosvn/svn*.protocol
.if empty(PORT_OPTIONS:MDOCS)
	${ECHO} "ADD_SUBDIRECTORY(man)" > ${WRKSRC}/doc/CMakeLists.txt
.endif
.if empty(PORT_OPTIONS:MNLS)
	${REINPLACE_CMD} -e 's,ADD_SUBDIRECTORY(po), ,g' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
