# ex:ts=8
# New ports collection makefile for:	libtecla
# Date created:		Feb 12, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtecla
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.astro.caltech.edu/~mcs/tecla/

MAINTAINER=	ports@FreeBSD.org

USE_SUBMAKE=	yes
USE_AUTOCONF=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	default
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
	REALCURDIR="${.CURDIR}" \
	PORTNAME="${PORTNAME}"
INSTALLS_SHLIB=	yes

post-extract:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/genman3list.sh

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.mk>
