# Created by: Yoichi Asai <yatt@msc.biglobe.ne.jp>
# $FreeBSD$

PKGNAMESUFFIX=	-tcltk

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk interface for TiMidity++

BROKEN=		fails to build: /bin/sh: tclsh: not found
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-08-26

OPTIONS_DEFINE=	DOCS

MASTERDIR=	${.CURDIR}/../../audio/timidity++

.include "${MASTERDIR}/Makefile"
