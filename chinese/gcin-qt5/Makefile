# Created by: vanilla@
# $FreeBSD$

PORTNAME=	gcin
PORTVERSION=	2.8.6
PORTREVISION=	3
CATEGORIES=	chinese textproc gnome
MASTER_SITES=	http://hyperrate.com/gcin-source/
PKGNAMESUFFIX=	-qt5
EXTRACT_ONLY=	gcin-${PORTVERSION}.tar.xz

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Traditional Chinese input utility in X

LICENSE=	LGPL21

LIB_DEPENDS=	libgcin-im-client.so:chinese/gcin

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/qt5-im
USES=		compiler:c++11-lang gmake pkgconfig qt:5 tar:xz
USE_QT=		qdbus qmake_build buildtools_build core gui
USE_CXXSTD=	c++11
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		MKDIR="${MKDIR}"

PLIST_FILES=	${QT_PLUGINDIR}/platforminputcontexts/libgcinplatforminputcontextplugin.so

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g; \
		s,%%MOC%%,${MOC},;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
