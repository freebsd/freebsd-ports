# Created by: miwi
# $FreeBSD$

PORTNAME=	kdepim-runtime
PORTVERSION=	4.4.11.1
PORTREVISION=	2
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/kdepim-${PORTVERSION}/src
DIST_SUBDIR=	KDE
PKGNAMESUFFIX=	44

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries for KDE-PIM applications

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs

CONFLICTS_INSTALL=	kdepim-runtime-4.*

USE_KDE4=	pimlibs kdeprefix kdehier sharedmime automoc4
USES=		cmake:outsource
USE_BZIP2=	yes
USE_QT4=	qmake_build moc_build rcc_build uic_build \
		corelib dbus gui network qtestlib xml
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	${GREP} -H -r "#include <q" ${WRKSRC} | ${CUT} -d: -f1 | uniq | \
		${XARGS} ${REINPLACE_CMD} -f ${FILESDIR}/qt3to4headers.txt

.include <bsd.port.mk>
