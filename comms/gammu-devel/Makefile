# New ports collection makefile for:   gammu
# Date created:        12 december 2003
# Whom:                Kirill Bezzubets <kirill@solaris.ru>
#
# $FreeBSD$
#

PORTNAME=	gammu
PORTVERSION=	1.17.0
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://dl.cihar.com/gammu/releases/ \
		http://dl.cihar.com/gammu/releases/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	GNU All Mobile Management Utilities

BUILD_DEPENDS+=	cmake:${PORTSDIR}/devel/cmake
RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DINSTALL_LIBDATA_DIR=${LOCALBASE}/libdata

USE_GNOME=	pkgconfig

.if defined(NOPORTDOCS)
EXTRA_PATCHES=files/extra-patch-CMakeLists.txt
.else
MAN1=		gammu.1 gammu-config.1
PORTDOCS=	*
.endif

do-configure:
	@(cd ${WRKSRC}; \
	${LOCALBASE}/bin/cmake ${CMAKE_ARGS})
	@${REINPLACE_CMD} -i '' -e 's:bash:sh:' -e 's:dialog:cdialog:' ${WRKSRC}/utils/gammu-config

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 700042
	@${REINPLACE_CMD} -e 's@ -Wno-pointer-sign@@g' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
