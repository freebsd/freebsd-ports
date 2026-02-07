PORTNAME=	quftp
PORTVERSION=	1.0.7
PORTREVISION=	7
CATEGORIES=	ftp
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scriptable FTP client
WWW=		https://quftp.sourceforge.net/

LICENSE=	GPLv2

USES=		ncurses readline
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CPPFLAGS+=	-DWANT_OBSOLETE_TYPEDEFS
LDFLAGS+=	-lpthread
PLIST_FILES=	bin/quftp share/man/man1/quftp.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/s|+=.*|= ${CFLAGS} ${CPPFLAGS}|' \
		${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quftp

.include <bsd.port.mk>
