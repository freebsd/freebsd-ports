# New ports collection makefile for:	jdb
# Date created:				28 June 2002
# Whom:					Lars Eggert <larse@isi.edu>
#
# $FreeBSD$
#

PORTNAME=	jdb
PORTVERSION=	1.13
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	JDB manipulates flat-ASCII databases from shell scripts

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --datadir=${PREFIX}/lib/jdb

.include <bsd.port.mk>
