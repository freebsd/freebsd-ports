# New ports collection makefile for:	cftp
# Version required:			0.9.3
# Date created:				14 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	cftp-0.9.3
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.giga.or.at/pub/nih/cftp/ \
		http://people.FreeBSD.org/~andy/distfiles/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/cftp
.for file in AUTHORS ChangeLog NEWS README THANKS TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cftp
.endfor
.endif

.include <bsd.port.mk>
