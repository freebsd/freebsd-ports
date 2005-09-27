# New ports collection makefile for:	TiMidity++
# Date created:		27 Feb 1999
# Whom:			Yoichi Asai <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

INTERFACE=	slang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Slang interface for TiMidity++

MASTERDIR=	${.CURDIR:H:H}/audio/timidity++-emacs
CONFIGURE_ARGS+=--with-includes=${LOCALBASE}/include	\
		--with-libraries=${LOCALBASE}/lib
PLIST_FILES=	lib/timidity/interface_s.so

.include "${MASTERDIR}/Makefile"
