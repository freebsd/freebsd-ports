# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/gstreamer-plugins-taglib/Makefile,v 1.3 2008/03/19 14:05:32 ahze Exp $

PORTREVISION=	2
CATEGORIES=	audio

COMMENT=	Gstreamer taglib plugin

BROKEN_armv6=		fails to compile: textidentificationframe.h file not found
BROKEN_armv7=		fails to compile: textidentificationframe.h file not found

GST_PLUGIN=	taglib

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer-plugins

.include "${MASTERDIR}/Makefile"
