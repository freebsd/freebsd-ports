# New ports collection makefile for:	ucl
# Date created:				29 January 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ucl
PORTVERSION=	0.92
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.oberhumer.com/opensource/ucl/download/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/compression

MAINTAINER=	sobomax@FreeBSD.org

INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-shared

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/uclpack \
		${PREFIX}/bin/uclpack
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for file in COPYING README
	${INSTALL_DATA}	${WRKSRC}/${file} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif

.include <bsd.port.mk>
