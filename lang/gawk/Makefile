# New ports collection makefile for:	gawk
# Date created:		Mi  21 Okt 1998 13:53:18 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$

PORTNAME=	gawk
PORTVERSION=	3.1.5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gawk

MAINTAINER=	krion@FreeBSD.org
COMMENT=	The GNU version of Awk

INFO=		gawk gawkinet

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500039
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-nowchar
.endif

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}

MAN1=		gawk.1 igawk.1 pgawk.1

PLIST_SUB=	VERSION=${PORTVERSION}

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
