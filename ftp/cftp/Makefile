# New ports collection makefile for:	cftp
# Version required:			0.9.1
# Date created:				14 October 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.3 1999/06/05 22:31:13 mharo Exp $
#

DISTNAME=	cftp-0.9.3
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.giga.or.at/pub/nih/cftp/

MAINTAINER=	andy@icc.surw.chel.su

GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/cftp
.for file in AUTHORS ChangeLog NEWS README THANKS TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cftp
.endfor
.endif

.include <bsd.port.mk>
