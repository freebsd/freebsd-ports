# New ports collection makefile for:	libelf
# Date created:		18 Apr 2001
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libelf
PORTVERSION=	0.8.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.stud.uni-hannover.de/~michael/software/ \
		ftp://ftp.stud.uni-hannover.de/pub/users/michael/
MASTER_SITE_SUBDIR=	libs .

MAINTAINER=	roam@FreeBSD.org
COMMENT=	"A public ELF file access library similar to libelf(3) in Solaris"

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS+=	--enable-shared --disable-compat
INSTALLS_SHLIB=	yes
PLIST_SUB+=	LIBVER=${PORTVERSION:R}
USE_GETTEXT=	yes

NOMAN=		defined

.include <bsd.port.mk>
