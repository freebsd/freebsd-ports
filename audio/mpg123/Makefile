# New ports collection makefile for:	mpg123
# Version required:		0.59o
# Date created:			25 June 1997
# Whom:				Carey Jones <mcj@acquiesce.org>
#
# $Id: Makefile,v 1.7 1998/09/28 01:50:59 steve Exp $
#

DISTNAME=	mpg123-0.59o
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.tu-clausthal.de/pub/unix/audio/mpg123/ \
		http://homepages.uni-tuebingen.de/student/michael.hipp/mpg123/

MAINTAINER=	jkoshy@freebsd.org

MAN1=		mpg123.1

.include <bsd.port.mk>

.if ${PORTOBJFORMAT} == "elf"
ALL_TARGET=	freebsd-elf
.else
ALL_TARGET=	freebsd
.endif
