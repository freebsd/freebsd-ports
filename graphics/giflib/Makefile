# New ports collection makefile for:	giflib
# Version required:	3.0
# Date created:		03 May 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1998/11/20 08:50:51 tg Exp $
#

DISTNAME=	giflib-3.0
CATEGORIES=	graphics
MASTER_SITES=	http://earthspace.net/~esr/giflib/

MAINTAINER=	tg@FreeBSD.ORG

USE_XLIB=	yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
GIFLIB=	libgif.so.3
.else
GIFLIB=	libgif.so.3.0
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/giflib
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/giflib
.endif
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
