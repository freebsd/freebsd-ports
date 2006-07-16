# New ports collection makefile for:	geda
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	projectmanager
PORTVERSION=	20060123
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/ \
		http://www.tinkerbox.org/projects/files/gEDA/
PKGNAMEPREFIX=	geda-
DISTNAME=	geda-${PORTVERSION}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	The gEDA's project manager

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
