# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	quftp
PORTVERSION=	1.0.7
PORTREVISION=	4
CATEGORIES=	ftp
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scriptable FTP client

LICENSE=	GPLv2

USES=		ncurses readline
GNU_CONFIGURE=	yes

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

PLIST_FILES=	bin/quftp man/man1/quftp.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CFLAGS/s|+=.*|= ${CFLAGS} ${CPPFLAGS}|' \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quftp

.include <bsd.port.mk>
