# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#   $MCom: ports/graphics/gimp/Makefile,v 1.16 2009/08/25 00:05:58 marcus Exp $
#

PORTNAME=	gimp
DISTVERSION?=	2.6.9
PORTREVISION?=	0
PORTEPOCH?=	2
CATEGORIES=	graphics gnome
MASTER_SITES?=	# empty
DISTFILES?=	# empty
EXTRACT_ONLY?=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for The Gimp

RUN_DEPENDS=	gimp-2.6:${PORTSDIR}/graphics/gimp-app

OPTIONS=	PYTHON "Python-fu support" Off \
		PRINT "Gutenprint (gimp-print) plugin" On \
		HELP "Install Gimp-Help (50+MB distfile)" Off

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_HELP)
RUN_DEPENDS+=	gimp-help*>0:${PORTSDIR}/graphics/gimp-help
.endif

.if defined(WITH_PYTHON)
RUN_DEPENDS+=	${LOCALBASE}/libexec/gimp/2.2/environ/pygimp.env:${PORTSDIR}/graphics/py-gimp
.endif

.if !defined(WITHOUT_PRINT)
RUN_DEPENDS+=	${LOCALBASE}/libexec/gimp/2.2/plug-ins/gutenprint:${PORTSDIR}/print/gimp-gutenprint
RUN_DEPENDS+=	gutenprint>0:${PORTSDIR}/print/gutenprint
.endif

do-install:	# empty

.include <bsd.port.post.mk>
