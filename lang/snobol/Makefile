# New ports collection makefile for:	snobol
# Date created:		Fri Sep  1 00:05:55 MDT 2000
# Whom:			Wes Peters <wes@softweyr.com>
#
# $FreeBSD$

PORTNAME=	snobol
PORTVERSION=	0.99.4
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.snobol4.com/

MAINTAINER=	wes@FreeBSD.org
COMMENT=	0.99.4 release of ``The Macro Implementation of SNOBOL4 in C''

MAN1= snobol4.1

.include <bsd.port.pre.mk>

# Fix GCC 3.x from freaking out over some of our pointers.
#
# I had to patch gendata.sno, so I patched the changes it produces
# in res.h as well.  To keep the port from trying to run gendata.sno
# (with your potentially nonexistant snobol compiler), touch it
# back to it's original mod time.

post-patch:
	touch -t 199705212205.21 ${WRKSRC}/gendata.sno

.include <bsd.port.post.mk>
