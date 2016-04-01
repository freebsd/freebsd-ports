# Created by: Yuan Jue <yuanjue@yuanjue.net>
# $FreeBSD$

PORTNAME=	kdesvn
DISTVERSION=	1.7.0
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	KDE frontend for Subversion

LICENSE=	GPLv2

LIB_DEPENDS=	libsvn_client-1.so:devel/subversion

CONFLICTS=	qsvn-[0-9]*

USES=		cmake:outsource compiler:c11 tar:xz
CMAKE_ARGS+=	-DSUBVERSION_INCLUDE_DIR=${LOCALBASE}/include/subversion-1 \
		-DMAN_INSTALL_DIR=${MANPREFIX}/man
USE_KDE4=	kdelibs kdeprefix automoc4
USE_LDCONFIG=	yes
USE_QT4=	corelib gui xml network dbus svg sql \
		qmake_build moc_build rcc_build uic_build linguist_build

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CMAKE_OFF=	-DBUILD_po=OFF
NLS_USES=	gettext

post-patch:
	${RM} ${WRKSRC}/src/kiosvn/svn*.protocol

post-patch-DOCS-off:
	${FIND} ${WRKSRC}/docs -name CMakeLists.txt | \
		${XARGS} ${REINPLACE_CMD} -n '/kde4_create_manpage/p'

.include <bsd.port.mk>
