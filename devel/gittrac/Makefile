# New ports collection makefile for:	gittrac
# Date created:			30 Apr 2008
# Whom:				Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gittrac
CATEGORIES=	devel

COMMENT=	Web-Based Bug And Patch-Set Tracking System For Git

RUN_DEPENDS=	git>=0:${PORTSDIR}/devel/git

MASTERDIR=	${.CURDIR}/../cvstrac
MAKE_ARGS=	APPNAME=gittrac
PKGMESSAGE=	${.CURDIR}/pkg-message

.include "${MASTERDIR}/Makefile"
