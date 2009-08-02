# New ports collection makefile for:	entity
# Date created:				15 June 2000
# Whom:					Jesse McConnell <jesse@cylant.com>
#
# $FreeBSD$
#

PORTNAME=	entity
PORTVERSION=	0.7.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A really rapid XML-based application development system

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-tcl=no

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_LDCONFIG=	${PREFIX}/lib/entity/clib

MAN1=		entity.1

.include <bsd.port.pre.mk>

post-install:
	${MKDIR} ${PREFIX}/share/entity
	cd ${WRKSRC}/apps && ${PAX} -r -w `${LS} | \
		${GREP} -v Makefile` ${PREFIX}/share/entity

.include <bsd.port.post.mk>
