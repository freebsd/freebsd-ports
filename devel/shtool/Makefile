# New ports collection makefile for:	shtool
# Version required:		1.4.6
# Date created:			26-Apr-1999
# Whom:				Ralf S. Engelschall
#
# $FreeBSD$
#

DISTNAME=	shtool-1.4.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.engelschall.com/sw/shtool/
MASTER_SITE_SUBDIR=	shtool

MAINTAINER=	rse@engelschall.com

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --enable-batch

MAN1=		shtool.1 shtoolize.1

.include <bsd.port.mk>
