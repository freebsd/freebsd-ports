# ex:ts=8
# New ports collection makefile for:	le
# Date created:				16 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	le
PORTVERSION=	1.5.8
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/util/texteditors/

MAINTAINER=	obrien@FreeBSD.org

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAN1=		le.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/le
.for file in FEATURES HISTORY NEWS README TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/le
.endfor
.endif

.include <bsd.port.mk>
