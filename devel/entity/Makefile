# New ports collection makefile for:	entity
# Date created:				15 June 2000
# Whom:					Jesse McConnell <jesse@cylant.com>
#
# $FreeBSD$
#

PORTNAME=	entity
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.entity.cx/Download/files/all-versions/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A really rapid XML-based application development system

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-tcl=no

USE_GMAKE=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes

MAN1=		entity.1

post-install:
	${LDCONFIG} -m ${PREFIX}/lib/entity/clib ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/entity
	cd ${WRKSRC}/apps && ${PAX} -r -w `${LS} | \
		${GREP} -v Makefile` ${PREFIX}/share/entity

.include <bsd.port.mk>
