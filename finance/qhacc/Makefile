# New ports collection makefile for:	qhacc
# Date created:		28 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	qhacc
PORTVERSION=	0.6.1a
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.ostrich-emulators.cx/qhacc/

MAINTAINER=	ports@FreeBSD.org

USE_QT2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt="${X11BASE}"

pre-build:
	@${RM} -f ${WRKSRC}/src/moc_*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/qhacc ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/qhacc
	${INSTALL_DATA} ${FILESDIR}/config ${PREFIX}/share/qhacc/config.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/qhacc
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${PREFIX}/share/doc/qhacc
.endif
	@${SED} -e "s:/usr/X11R6:${PREFIX}:g" ${PKGMESSAGE}

.include <bsd.port.mk>
