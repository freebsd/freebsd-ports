# New ports collection makefile for:	qhacc
# Version required:	0.2.6
# Date created:		28 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	qhacc-0.2.6
CATEGORIES=	misc
MASTER_SITES=	http://people.FreeBSD.org/~cpiazza/distfiles/

MAINTAINER=	andrews@technologist.com

USE_X_PREFIX=	yes
USE_QT2=	yes
MAKE_ENV+=	QTDIR=${PREFIX} CXX="${CXX}" CC="${CC}"
WRKSRC=		${WRKDIR}/qhacc

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/qhacc ${PREFIX}/bin/qhacc.exec
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${FILESDIR}/qhacc.sh \
		> ${PREFIX}/bin/qhacc
	@${CHMOD} 755 ${PREFIX}/bin/qhacc
	@${MKDIR} ${PREFIX}/share/qhacc
	@${INSTALL_DATA} ${FILESDIR}/config ${PREFIX}/share/qhacc/config.sample

.include <bsd.port.mk>
