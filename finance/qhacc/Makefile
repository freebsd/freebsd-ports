# New ports collection makefile for:	qhacc
# Date created:		28 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	qhacc
PORTVERSION=	0.5
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.ostrich-emulators.cx/qhacc/

MAINTAINER=	ports@FreeBSD.org

USE_QT2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt="${X11BASE}"
MAKE_ENV+=	QTDIR=${PREFIX} CXX="${CXX}" CC="${CC}"

pre-build:
	@${RM} -f ${WRKSRC}/src/moc_*.cpp

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/qhacc ${PREFIX}/bin/qhacc.exec
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${FILESDIR}/qhacc.sh \
		> ${PREFIX}/bin/qhacc
	@${CHMOD} 755 ${PREFIX}/bin/qhacc
	@${MKDIR} ${PREFIX}/share/qhacc
	@${INSTALL_DATA} ${FILESDIR}/config ${PREFIX}/share/qhacc/config.sample

.include <bsd.port.mk>
