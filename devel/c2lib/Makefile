# ex:ts=8
# New ports collection makefile for:	c2lib
# Date created:			Feb 16, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c2lib
PORTVERSION=	1.2.8
CATEGORIES=	devel
MASTER_SITES=	http://www.annexia.org/freeware/c2lib/

MAINTAINER=	ijliao@FreeBSD.org

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
	REALCURDIR="${.CURDIR}" \
	DISTNAME="${DISTNAME}"

post-extract:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/genman3list.sh

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.mk>
