# New ports collection makefile for:	entity
# Date created:				15 June 2000
# Whom:					Jesse McConnell <jesse@cylant.com>
#
# $FreeBSD$
#

PORTNAME=	entity
PORTVERSION=	0.7.2
CATEGORIES=	devel
MASTER_SITES=	http://entity.evilplan.org/Download/files/all-versions/

MAINTAINER=	jesse@cylant.com

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-tcl=no \
		--enable-python=no
USE_GMAKE=	yes
USE_GTK=	yes
INSTALLS_SHLIB=	yes

MAN1=		entity.1

post-install:
	${LDCONFIG} -m ${PREFIX}/lib/entity/clib ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/entity
	cd ${WRKSRC}/apps && \
		pax -r -w `ls | ${GREP} -v Makefile` ${PREFIX}/share/entity

.include <bsd.port.mk>
