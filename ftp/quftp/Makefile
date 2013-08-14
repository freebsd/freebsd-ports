# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	quftp
PORTVERSION=	1.0.7
PORTREVISION=	4
CATEGORIES=	ftp
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scriptable FTP client

LICENSE=	GPLv2

USES=		ncurses readline
GNU_CONFIGURE=	yes

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

MAN1=		quftp.1
PLIST_FILES=	bin/quftp

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS|#CFLAGS|' ${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/quftp

.include <bsd.port.mk>
