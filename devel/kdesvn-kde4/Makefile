# Created by: Yuan Jue <yuanjue@yuanjue.net>
# $FreeBSD$

PORTNAME=	kdesvn
DISTVERSION=	1.7.0
PORTREVISION=	12
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE frontend for Subversion

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libsvn_client-1.so:devel/subversion \
		libapr-1.so:devel/apr1 \
		libgdbm.so:databases/gdbm \
		libexpat.so:textproc/expat2

CONFLICTS=	kdesvn-2.* \
		qsvn-[0-9]*

CMAKE_ARGS+=	-DSUBVERSION_INCLUDE_DIR=${LOCALBASE}/include/subversion-1 \
		-DMAN_INSTALL_DIR=${MANPREFIX}/man

USES=		cmake compiler:c11 bdb kde:4 qt:4 tar:xz
USE_KDE=	automoc4 kdelibs soprano baseapps_run
USE_LDCONFIG=	yes
USE_QT=		corelib gui xml network dbus svg sql \
		qmake_build moc_build rcc_build uic_build linguist_build

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CMAKE_OFF=	-DBUILD_po=OFF
NLS_USES=	gettext

PORTSCOUT=	limit:1\.7.*

post-patch:
	${RM} ${WRKSRC}/src/kiosvn/svn*.protocol

post-patch-DOCS-off:
	${FIND} ${WRKSRC}/docs -name CMakeLists.txt | \
		${XARGS} ${REINPLACE_CMD} -n '/kde4_create_manpage/p'

.include <bsd.port.mk>
