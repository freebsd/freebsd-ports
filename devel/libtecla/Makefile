# ex:ts=8
# New ports collection makefile for:	libtecla
# Date created:		Feb 12, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtecla
PORTVERSION=	1.6.0
CATEGORIES=	devel
MASTER_SITES=	http://www.astro.caltech.edu/~mcs/tecla/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive command line editing facilities

USE_SUBMAKE=	yes
USE_AUTOCONF_VER=	253
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	default
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
	REALCURDIR="${.CURDIR}" \
	PORTNAME="${PORTNAME}"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500000
PLIST_SUB+=	THREADS="@comment "
.else
PLIST_SUB+=	THREADS=""
.endif

post-extract:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/genmanlist.sh

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.post.mk>
