# New ports collection makefile for:	ssed
# Date created:		28 May 2002
# Whom:			verm
#
# $FreeBSD$
#

PORTNAME=	ssed
PORTVERSION=	3.58
PORTREVISION=	2
CATEGORIES=	editors textproc
MASTER_SITES=	http://queen.rett.polimi.it/~paolob/seders/ssed/
DISTNAME=	sed-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Super-sed is a heavily enhanced version of sed

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} --program-prefix=s

MAN1=	ssed.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
