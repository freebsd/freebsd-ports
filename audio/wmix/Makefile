# New ports collection makefile for:   wmix
# Date created:		2 April 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	wmix
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	An audio mixer for the WindowMaker dock with TV-like OSD

PLIST_FILES=	bin/wmix
ALL_TARGET=	${PORTNAME}
USE_XPM=	yes
USE_X_PREFIX=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${X11BASE}/include" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib"

PORTDOCS=	AUTHORS BUGS INSTALL NEWS README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmix ${PREFIX}/bin

post-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
