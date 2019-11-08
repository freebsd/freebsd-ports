# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	hot-babe
PORTVERSION=	0.2.2
PORTREVISION=	9
CATEGORIES=	deskutils
MASTER_SITES=	http://dindinx.net/hotbabe/downloads/ \
		LOCAL/novel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small utility which displays the system activity in a special way

USES=		gnome pkgconfig tar:bzip2
MAKE_ARGS+=	PREFIX="${PREFIX}" CC="${CC}"
USE_GNOME=	gtk20

PORTDOCS=	ChangeLog NEWS TODO LICENSE CONTRIBUTORS copyright config.example

OPTIONS_DEFINE=	DOCS

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning! This port contains some adults only content."
	@${ECHO_MSG} "You might hit Ctrl-C to abort."
	@${ECHO_MSG}

post-install:
	${INSTALL_MAN} ${WRKSRC}/hot-babe.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
