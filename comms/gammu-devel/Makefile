# New ports collection makefile for:   gammu
# Date created:        12 december 2003
# Whom:                Kirill Bezzubets <kirill@solaris.ru>
#
# $FreeBSD$
#

PORTNAME=	gammu
PORTVERSION=	1.13.0
CATEGORIES=	comms
MASTER_SITES=	ftp://dl.cihar.com/gammu/releases/ \
		http://dl.cihar.com/gammu/releases/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	GNU All Mobile Management Utilities

BUILD_DEPENDS+=	cmake:${PORTSDIR}/devel/cmake

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_INSTALL_PREFIX=${PREFIX}

MAN1=		gammu.1 gammu-config.1
USE_GNOME=	pkgconfig

PORTDOCS=	*

do-configure:
	@(cd ${WRKSRC}; \
	${LOCALBASE}/bin/cmake ${CMAKE_ARGS})

.include <bsd.port.pre.mk>
post-patch:
.if ${OSVERSION} < 700042
	@${REINPLACE_CMD} -e 's@ -Wno-pointer-sign@@g' ${WRKSRC}/CMakeLists.txt
.endif
.if defined(NOPORTDOCS)
EXTRA_PATCHES=files/extra-patch-CMakeLists.txt
.endif

.include <bsd.port.post.mk>
