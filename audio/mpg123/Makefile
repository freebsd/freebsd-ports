# New ports collection makefile for:	mpg123
# Version required:		0.59o
# Date created:			25 June 1997
# Whom:				Carey Jones <mcj@acquiesce.org>
#
# $Id: Makefile,v 1.8 1998/10/03 12:09:54 jkoshy Exp $
#

DISTNAME=	mpg123-0.59o
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.tu-clausthal.de/pub/unix/audio/mpg123/ \
		http://homepages.uni-tuebingen.de/student/michael.hipp/mpg123/

MAINTAINER=	jkoshy@freebsd.org

MAN1=		mpg123.1

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
ALL_TARGET=	freebsd-elf
.else
ALL_TARGET=	freebsd
.endif

.include <bsd.port.post.mk>
