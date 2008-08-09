# Ports collection makefile for:	esperanza
# Date created:			23 Feb 2007
# Whom:				Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	esperanza
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://xmms2.xmms.se/~tru/esperanza/0.3/

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Advanced QT4 XMMS2 client

BUILD_DEPENDS=	${LOCALBASE}/lib/libxmmsclient++.so.3:${PORTSDIR}/audio/cpp-xmms2
RUN_DEPENDS=	${LOCALBASE}/lib/libxmmsclient++.so.3:${PORTSDIR}/audio/cpp-xmms2

BROKEN=		does not build

USE_QT_VER=	4
QT_COMPONENTS=	gui moc qmake rcc uic xml network imageformats
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/esperanza

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} esperanza.pro

.include <bsd.port.mk>
