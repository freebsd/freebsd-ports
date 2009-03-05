# New ports collection makefile for:	mydumper
# Date created:		2009-03-04
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	mydumper
PORTVERSION=	0.1.5
CATEGORIES=	databases
MASTER_SITES=	http://code.launchpad.net/mydumper/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	gslin@gslin.org
COMMENT=	MySQL Data Dumper

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

FETCH_ARGS?=	-pRr
PLIST_FILES=	sbin/mydumper
USE_GNOME=	glib20
USE_MYSQL=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mydumper ${PREFIX}/sbin

.include <bsd.port.mk>
