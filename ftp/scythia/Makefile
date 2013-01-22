# New ports collection makefile for:	scythia
# Date created:		30 Jun 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	scythia
DISTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	http://scythia.free.fr/wp-content/ \
		ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/
DISTNAME=	${PORTNAME}_${PORTVERSION}-2-src

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Small ftp client unpretentious based on Qt4

USE_QT4=	gui network corelib qmake_build uic_build moc_build rcc_build
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.if defined(NOPORTDOCS)
INSTALL_TARGET=install_lang install_icon install_icon2 install_target
.endif

DESKTOP_ENTRIES=	"Scythia" \
			"Small ftp client unpretentious" \
			"scythia" \
			"scythia" \
			"Network;FileTransfer;Qt;" \
			"false"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		-e '/unix:desktop/d' \
		${WRKSRC}/scythia.pro
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/src/main.cpp

pre-build:
	@cd ${BUILD_WRKSRC} && \
	       ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX} scythia.pro

.include <bsd.port.mk>
