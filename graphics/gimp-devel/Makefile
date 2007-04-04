# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#   $MCom: ports/graphics/gimp-devel/Makefile,v 1.30 2007/04/03 17:42:21 ahze Exp $
#

PORTNAME=	gimp
PORTVERSION?=	2.3
PORTEPOCH?=	2
CATEGORIES=	graphics gnome
MASTER_SITES?=	# empty
PKGNAMESUFFIX=	-devel
DISTFILES?=	# empty
EXTRACT_ONLY?=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for The Gimp

RUN_DEPENDS=	gimp-2.3:${PORTSDIR}/graphics/gimp-app-devel

OPTIONS=	PYTHON "Python-fu support" Off \
		PRINT "Gutenprint (gimp-print) plugin" On
#		HELP "Install Gimp-Help (50+MB distfile)" Off

NO_BUILD=	yes

.include <bsd.port.pre.mk>

pre-everything::
	@if [ -n "`${PKG_INFO} -xI '^gimp-devel-[0-9].[0-9].[0-9]*' 2>/dev/null`" ]; then \
		${ECHO_CMD} "${PKGNAME}: Old version of gimp detected! Please see ${PORTSDIR}/UPDATING for information on upgrading ${PKGNAME}" ; \
		${FALSE}; \
	fi

#.if defined(WITH_HELP)
#RUN_DEPENDS+=	gimp-help>0:${PORTSDIR}/graphics/gimp-help
#.endif

.if defined(WITH_PYTHON)
RUN_DEPENDS+=	${LOCALBASE}/libexec/gimp/2.2/environ/pygimp.env:${PORTSDIR}/graphics/py-gimp
.endif

.if !defined(WITHOUT_PRINT)
RUN_DEPENDS+=	${LOCALBASE}/libexec/gimp/2.2/plug-ins/print:${PORTSDIR}/print/gimp-gutenprint
.endif

do-install:	# empty

.include <bsd.port.post.mk>
