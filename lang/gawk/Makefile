# New ports collection makefile for:	gawk
# Date created:		Mi  21 Okt 1998 13:53:18 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$

PORTNAME=	gawk
PORTVERSION=	3.1.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gawk

MAINTAINER=	dd@FreeBSD.org
COMMENT=	The GNU version of Awk

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500039
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-nowchar
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}
MAN1=		gawk.1 igawk.1

PLIST_SUB=	VERSION=${PORTVERSION}
USE_GETTEXT=	yes

.include <bsd.port.post.mk>
