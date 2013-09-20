# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	minitunes
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://flavio.tordini.org/files/${PORTNAME}/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Minitunes is just another music player

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib

NO_STAGE=	yes
USE_QT4=	dbus gui moc_build network phonon qmake_build rcc_build \
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
