# New ports collection makefile for:	PostgreSQL tcltk
# Date created:		7 Jun 2000
# Whom:			Tomokatsu Saito <saito@a2z.co.jp>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTREVISION=	0
CATEGORIES=	japanese databases tcl${TCLVERSION:C/[^0-9]//g}
PKGNAMESUFFIX=	-tcltk

MAINTAINER=	saito@a2z.co.jp
COMMENT=	A TCL interface to the database PostgreSQL, including a tk GUI

TCLVERSION?=	8.0jp

TCLPORTDIR=	${PORTSDIR}/japanese/tcl
TKPORTDIR=	${PORTSDIR}/japanese/tk

.include <${.CURDIR}/../../databases/postgresql-tcltk/Makefile>
