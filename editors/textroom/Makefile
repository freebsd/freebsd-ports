# New ports collection makefile for: textroom
# Date created:        27 April 2010
# Whom:                admin@mjbrune.org
#
# $FreeBSD$
#

PORTNAME=	textroom
PORTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	SF

MAINTAINER=	admin@mjbrune.org
COMMENT=	A full screen text editor

BUILD_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info
LIB_DEPENDS=	hunspell-1.3:${PORTSDIR}/textproc/hunspell \
		xml++-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		curl.6:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

USE_SDL=	mixer
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build corelib gui xml \
		svg opengl qt3support
QMAKE_ARGS=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}
HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/application/src/textroom.cpp
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/application/src/getaword.cpp
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/application/src/optionsdialog.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS} textroom.pro

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
