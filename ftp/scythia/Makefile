# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	scythia
DISTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	http://scythia.free.fr/wp-content/ \
		ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/
DISTNAME=	${PORTNAME}_${PORTVERSION}-2-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small ftp client unpretentious based on Qt4

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake qt:4
USE_QT=		gui network corelib uic_build moc_build rcc_build
INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

DOCS_INSTALL_TARGET_OFF=	install_lang install_icon install_icon2 install_target

DESKTOP_ENTRIES=	"Scythia" \
			"Small ftp client unpretentious" \
			"scythia" \
			"scythia" \
			"Network;FileTransfer;Qt;" \
			"true"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		-e '/unix:desktop/d' \
		${WRKSRC}/scythia.pro
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
