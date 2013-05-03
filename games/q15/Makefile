# Created by: Andrej Zverev <az@inec.ru>
# $FreeBSD$

PORTNAME=	q15
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://silversoft.net/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Qt-based game fifteen

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_QT_VER=	3
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}" \
		QT_PREFIX="${QT_PREFIX}"

PLIST_FILES=	bin/q15

post-patch:
	@${REINPLACE_CMD} -e "s,NOMAN,NO_MAN,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/q15 ${PREFIX}/bin

.include <bsd.port.mk>
