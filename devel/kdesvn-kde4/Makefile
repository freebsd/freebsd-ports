# Created by: Yuan Jue <yuanjue@yuanjue.net>
# $FreeBSD$

PORTNAME=	kdesvn
DISTVERSION=	1.7.0
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	KDE frontend for Subversion

LICENSE=	GPLv2

LIB_DEPENDS=	libsvn_client-1.so:${PORTSDIR}/devel/subversion

CONFLICTS=	qsvn-[0-9]*

USES=		cmake:outsource tar:xz
CMAKE_ARGS+=	-DSUBVERSION_INCLUDE_DIR=${LOCALBASE}/include/subversion-1 \
		-DMAN_INSTALL_DIR=${MANPREFIX}/man
USE_KDE4=	kdelibs kdeprefix automoc4
USE_LDCONFIG=	yes
USE_QT4=	corelib gui xml network dbus svg sql \
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
