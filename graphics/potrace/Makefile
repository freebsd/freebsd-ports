# Ports collection makefile for:	potrace
# Date created:				24 September 2003
# Whom:					Piotr Smyrak <smyru@heron.pl>
#
# $FreeBSD$
#

PORTNAME=	potrace
PORTVERSION=	1.7
CATEGORIES=	graphics
MASTER_SITES=	http://potrace.sourceforge.net/download/

MAINTAINER=	smyru@heron.pl
COMMENT=	Transforms bitmaps into vector graphics

GNU_CONFIGURE=	yes

MAN1=		potrace.1 mkbitmap.1
PLIST_FILES=	bin/potrace bin/mkbitmap

.if defined(A4)
CONFIGURE_ARGS+=	--enable-a4
.endif

.if defined(WITH_METRIC)
CONFIGURE_ARGS+=	--enable-metric
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may define the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    WITH_METRIC      Enable use of metric units (centimeters) as default"
	@${ECHO_MSG} "    A4               Enable use of A4 as the default papersize"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
