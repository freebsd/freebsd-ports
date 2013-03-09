# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	tea
DISTVERSION=	34.0.1
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}-editor/${PORTNAME}-editor/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and powerful Qt4-based text editor

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_QT4=	qmake_build moc_build rcc_build gui xml
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	ASPELL
OPTIONS_DEFAULT=	ASPELL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell
QMAKEFLAGS=	USE_ASPELL=true
.else
QMAKEFLAGS=	USE_ASPELL=false
.endif

post-patch:
	@${REINPLACE_CMD} -e '/aspell/s,/usr,${LOCALBASE},' ${WRKSRC}/src.pro

do-configure:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
