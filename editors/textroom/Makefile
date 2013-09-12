# Created by: admin@mjbrune.org
# $FreeBSD$

PORTNAME=	textroom
PORTVERSION=	0.8.2
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full screen text editor

LIB_DEPENDS=	libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell \
		libxml++-2.6.so:${PORTSDIR}/textproc/libxml++26 \
		libcurl.so:${PORTSDIR}/ftp/curl

USES=		shared-mime-info
USE_SDL=	mixer
USE_QT4=	moc_build qmake_build rcc_build uic_build corelib gui xml \
		svg opengl qt3support
QMAKE_ARGS=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}
HAS_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/application/src/textroom.cpp \
		${WRKSRC}/application/src/getaword.cpp \
		${WRKSRC}/application/src/optionsdialog.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS} textroom.pro

.include <bsd.port.mk>
