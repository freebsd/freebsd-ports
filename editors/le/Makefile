# ex:ts=8
# New ports collection makefile for:	le
# Date created:				16 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	le
PORTVERSION=	1.9.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.yars.free.net/pub/software/unix/util/texteditors/
MASTER_SITE_SUBDIR=	apps/editors/terminal

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAN1=		le.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in FEATURES HISTORY NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
