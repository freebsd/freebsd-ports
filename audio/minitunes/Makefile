# New ports collection makefile for:	minitunes
# Date created:		2010-07-06
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	minitunes
PORTVERSION=	0.1
CATEGORIES=	audio
MASTER_SITES=	http://flavio.tordini.org/files/${PORTNAME}/

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Minitunes is just another music player

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib

USE_QT_VER=	4
QT_COMPONENTS=	dbus gui moc_build network phonon qmake_build rcc_build \
		sql uic_build xml
INSTALLS_ICONS=	yes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

QMAKEFLAGS+=	PREFIX="${PREFIX}"

WRKSRC=		${WRKDIR}/${PORTNAME}

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${PORTNAME}.pro

.include <bsd.port.mk>
