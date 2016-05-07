# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	svntrac
PORTREVISION=	4
CATEGORIES=	devel

COMMENT=	Web-Based Bug And Patch-Set Tracking System For Subversion

RUN_DEPENDS=	subversion>=0:devel/subversion

MASTERDIR=	${.CURDIR}/../cvstrac
MAKE_ARGS=	APPNAME=svntrac
PKGMESSAGE=	${.CURDIR}/pkg-message

.include "${MASTERDIR}/Makefile"
