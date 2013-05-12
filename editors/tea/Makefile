# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	tea
DISTVERSION=	35.0.0
CATEGORIES=	editors
MASTER_SITES=	http://semiletov.org/tea/dloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and powerful Qt4-based text editor

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_DOS2UNIX=	rvln.*
USE_QT4=	gui moc_build qmake_build rcc_build
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_RADIO=		SPELL
OPTIONS_RADIO_SPELL=	ASPELL HUNSPELL
OPTIONS_DEFAULT=	ASPELL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
QMAKEFLAGS+=	USE_ASPELL=true
.else
QMAKEFLAGS+=	USE_ASPELL=false
.endif

.if ${PORT_OPTIONS:MHUNSPELL}
LIB_DEPENDS+=	hunspell-1.3:${PORTSDIR}/textproc/hunspell
QMAKEFLAGS+=	USE_HUNSPELL=true
.else
QMAKEFLAGS+=	USE_HUNSPELL=false
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/include|${LOCALBASE}/include|' ${WRKSRC}/src.pro

do-configure:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
