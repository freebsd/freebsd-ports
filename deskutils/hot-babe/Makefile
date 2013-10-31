# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	hot-babe
PORTVERSION=	0.2.2
PORTREVISION=	8
CATEGORIES=	deskutils
MASTER_SITES=	http://dindinx.net/hotbabe/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	novel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Small utility which displays the system activity in a special way

USES=		pkgconfig
USE_BZIP2=	yes
MAKE_ARGS+=	PREFIX="${PREFIX}" CC="${CC}"
USE_GNOME=	gtk20

MAN1=	hot-babe.1

PORTDOCS=	ChangeLog NEWS TODO LICENSE CONTRIBUTORS copyright config.example

NO_STAGE=	yes
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning! This port contains some adults only content."
	@${ECHO_MSG} "You might hit Ctrl-C to abort."
	@${ECHO_MSG}

post-install:
	${INSTALL_MAN} ${WRKSRC}/hot-babe.1 ${PREFIX}/man/man1
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
