# New ports collection makefile for:	le
# Version required:			1.5.2
# Date created:				16 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		le-1.5.2
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			ftp://ftp.yars.free.net/pub/software/unix/util/texteditors/
MASTER_SITE_SUBDIR=	apps/editors/terminal

MAINTAINER=		andy@icc.surw.chel.su

GNU_CONFIGURE=		yes
MAN1=			le.1

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/le
.for file in COPYING FEATURES HISTORY NEWS README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/le
.endfor
.endif

.include <bsd.port.mk>
