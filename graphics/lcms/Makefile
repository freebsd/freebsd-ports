# New ports collection makefile for:	lcms
# Date created:		October 30, 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	lcms
PORTVERSION=	1.06
CATEGORIES=	graphics
MASTER_SITES=	http://www.abaforum.es/martim/

MAINTAINER=	mi@aldan.algebra.com

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.ifndef NOPORTDOCS
PLIST_SUB=	DOC=""
.else
PLIST_SUB=	DOC="@comment "
.endif

.ifndef NOPORTDOCS
post-install:
	${MKDIR} ${PREFIX}/share/doc/lcms
	${CP} -rp ${WRKSRC}/doc/* ${PREFIX}/share/doc/lcms/
.endif

.include <bsd.port.mk>
