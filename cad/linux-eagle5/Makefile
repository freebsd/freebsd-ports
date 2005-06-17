# New ports collection makefile for:	linux-eagle
# Date created:				29 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-eagle
EAGLEVERSION?=	4.13
EAGLELANG?=	eng
PORTVERSION=	${EAGLEVERSION:S/r/./}
PORTREVISION=	1
CATEGORIES?=	cad linux
MASTER_SITES=	ftp://ftp.cadsoft.de/pub/program/${EAGLEVERSION}/
DISTNAME=	${PORTNAME:S/linux-//}-lin-${EAGLELANG}-${EAGLEVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER?=	riggs@rrr.de
COMMENT?=	An easy to use, yet powerful tool for designing printed circuit boards

CONFLICTS?=	de-linux-eagle-*

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME:S/linux-//}-lin-${EAGLELANG}-${EAGLEVERSION}
DATADIR=	${PREFIX}/share/${PORTNAME:S/linux-//}

RESTRICTED=	"Usage permitted for non-commercial purposes only"
NO_CDROM=	"Sale for profit is not permitted"

USE_LINUX=	yes
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		eagle.1

CPIO?=		/usr/bin/cpio --quiet -pdum -R

do-install:
	@${MKDIR} ${DATADIR}
	@ cd ${WRKSRC} && ${FIND} * -type f -print | ${CPIO} ${BINOWN}:${BINGRP} ${DATADIR}
	@ cd ${DATADIR} && ${FIND} * -type d -print | ${XARGS} ${CHMOD} 0755
	@${LN} -sf ${DATADIR}/bin/eagle ${PREFIX}/bin/eagle
	@${INSTALL_MAN} ${DATADIR}/man/eagle.1 ${PREFIX}/man/man1

post-install:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${PKGDIR}/pkg-message > \
		${PKGMESSAGE}
.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
