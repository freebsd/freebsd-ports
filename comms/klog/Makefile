PORTNAME=	klog
PORTVERSION=	2.4.2
PORTREVISION=	2
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Simple Qt-based amateur radio logger
WWW=		https://github.com/ea4k/klog/wiki

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhamlib.so:comms/hamlib
USES=		compiler:c++17-lang gl qmake qt:6 xorg
USE_GITHUB=	yes
USE_GL=		opengl
USE_QT=		base declarative charts location positioning serialport \
		sqldriver-sqlite:run tools:build
GH_ACCOUNT=	ea4k
GH_PROJECT=	klog

# https://github.com/ea4k/klog/issues/419
DESKTOP_ENTRIES="KLog" "Simple Amateur Radio Logging Program" \
		"" "klog" "Network;HamRadio;" \
		false

post-patch:
	@${REINPLACE_CMD} \
		's|"\/usr\/share\/klog\/translations\/klog_"|"${DATADIR}/translations/klog_"|' \
		${WRKSRC}/src/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/build/target/klog ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/src/build/target/translations/klog_*.qm \
		${STAGEDIR}${DATADIR}/translations
	${INSTALL_MAN} ${WRKSRC}/src/klog.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
