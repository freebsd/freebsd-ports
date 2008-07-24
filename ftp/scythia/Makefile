# New ports collection makefile for:	scythia
# Date created:		30 Jun 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	scythia
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	http://scythia.free.fr/file/ \
		ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/
DISTNAME=	${PORTNAME}_${PORTVERSION}-src

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A small ftp client unpretentious based on QT4

USE_QT_VER=	4
QT_COMPONENTS=	gui network corelib qmake_build uic_build moc_build rcc_build
INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.if defined(NOPORTDOCS)
INSTALL_TARGET=install_lang install_icon install_icon2 install_target
.endif

DESKTOP_ENTRIES=	"Scythia" \
			"A small ftp client unpretentious" \
			"scythia" \
			"scythia" \
			"Application;Network;" \
			"false"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		-e '/unix:desktop/d' \
		${WRKSRC}/scythia.pro
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/src/main.cpp

pre-build:
	@cd ${BUILD_WRKSRC} && \
	       ${SETENV} ${MAKE_ENV} ${QMAKE} -unix PREFIX=${PREFIX} scythia.pro

.include <bsd.port.mk>
