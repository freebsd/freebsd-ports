PORTNAME=	hexcurse
DISTVERSIONPREFIX=	v
DISTVERSION=	1.70.0
CATEGORIES=	editors

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Versatile ncurses-based hex editor
WWW=		https://github.com/prso/hexcurse-ng

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	prso
GH_PROJECT=	${PORTNAME}-ng

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/hexcurse share/man/man1/hexcurse.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's, getopt\.c,,' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's,hgetopt,getopt,' ${WRKSRC}/src/hexcurse.c

.include <bsd.port.mk>
