# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	basic256
PORTVERSION=	0.9.9.28
CATEGORIES=	lang
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	kidbasic/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Easy to use BASIC language and IDE for education

BUILD_DEPENDS=	espeak:${PORTSDIR}/audio/espeak \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		flex:${PORTSDIR}/textproc/flex

WRKSRC=		${WRKDIR}

USE_BISON=	build
USE_SDL=	sdl mixer
USE_QT4=	corelib gui network xml webkit moc_build qmake_build rcc_build uic_build
USE_DOS2UNIX=	yes
HAS_CONFIGURE=	yes

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${QMAKE} "PREFIX=${PREFIX}" BASIC256.pro

.include <bsd.port.mk>
