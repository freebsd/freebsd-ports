# ex:ts=8
# New ports collection makefile for:	c2lib
# Date created:			Feb 16, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c2lib
PORTVERSION=	1.2.15
CATEGORIES=	devel
MASTER_SITES=	http://www.annexia.org/freeware/c2lib/

MAINTAINER=	alane@FreeBSD.org

USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
	REALCURDIR="${.CURDIR}" \
	DISTNAME="${DISTNAME}"

post-install:
	${RM} ${PREFIX}/lib/libc2.la

.include <bsd.port.pre.mk>

MAN3!=		${CAT} ${FILESDIR}/man3

.include <bsd.port.post.mk>
