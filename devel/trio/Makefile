# ex:ts=8
# New ports collection makefile for:	trio
# Date created:			Jun 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	trio
PORTVERSION=	1.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ctrio

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
.for file in trio.h triop.h
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include
.endfor
	${INSTALL_DATA} ${WRKSRC}/libtrio.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc ${DOCSDIR}
	${CP} -R ${WRKSRC}/html ${DOCSDIR}
.endif

.include <bsd.port.mk>
