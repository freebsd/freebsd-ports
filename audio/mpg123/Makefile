# New ports collection makefile for:	mpg123
# Version required:		0.59o
# Date created:			25 June 1997
# Whom:				Carey Jones <mcj@acquiesce.org>
#
# $Id: Makefile,v 1.9 1998/11/14 09:43:03 asami Exp $
#

DISTNAME=	mpg123-0.59o
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.tu-clausthal.de/pub/unix/audio/mpg123/ \
		http://ftp.tu-clausthal.de/pub/unix/audio/mpg123/ \
		http://www-ti.informatik.uni-tuebingen.de/~hippm/mpg123/

MAINTAINER=	jkoshy@freebsd.org

MAN1=		mpg123.1

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
ALL_TARGET=	freebsd-elf
.else
ALL_TARGET=	freebsd
.endif

.include <bsd.port.post.mk>
