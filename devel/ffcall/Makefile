# New ports collection makefile for:   ffcall
# Date created:        21 February 2001
# Whom:                jagapen@home.com
#
# $FreeBSD$
#

PORTNAME=	ffcall
PORTVERSION=	1.8d
PORTREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=  ftp://ftp.santafe.edu/pub/gnu/
MASTER_SITES=	${MASTER_SITE_GNUSTEP} \
		ftp://ftp.gnustep.org/pub/gnustep/libs/
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Foreign function call libraries

USE_GMAKE=	yes
USE_LIBTOOL=	yes
ONLY_FOR_ARCHS=	i386 alpha ia64

MAN3=		avcall.3 callback.3 trampoline.3 trampoline_r.3 vacall.3
MANCOMPRESSED=	no

.include <bsd.port.mk>
