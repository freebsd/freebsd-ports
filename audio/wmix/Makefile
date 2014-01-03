# Created by: Konstantinos Konstantinidis <kkonstan@daemon.gr>
# $FreeBSD$

PORTNAME=	wmix
PORTVERSION=	3.1
PORTREVISION=	3
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	An audio mixer for the WindowMaker dock with TV-like OSD

PLIST_FILES=	bin/wmix
ALL_TARGET=	${PORTNAME}
USE_XORG=	xpm
NO_STAGE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

PORTDOCS=	AUTHORS BUGS INSTALL NEWS README

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmix ${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
