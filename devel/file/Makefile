# New ports collection makefile for:	file
# Date created:		29 July 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	file
PORTVERSION=	4.03
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.astron.com/pub/file/

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A tool to determine file types

#USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		file.1
MAN3=		libmagic.3
MAN4=		magic.4

post-install:
	${RM} -f ${PREFIX}/lib/libmagic.la

.include <bsd.port.mk>
