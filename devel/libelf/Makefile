# New ports collection makefile for:	libelf
# Date created:		18 Apr 2001
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libelf
PORTVERSION=	0.7.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.stud.uni-hannover.de/~michael/software/ \
		ftp://ftp.stud.uni-hannover.de/pub/users/michael/
MASTER_SITE_SUBDIR=	libs .

MAINTAINER=	roam@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
INSTALLS_SHLIB=	yes
PLIST_SUB+=	LIBVER=${PORTVERSION} \
		LIBVER_SHORT=${PORTVERSION:R}

NOMAN=		defined

.include <bsd.port.mk>
