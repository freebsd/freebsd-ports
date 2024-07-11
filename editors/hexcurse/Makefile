PORTNAME=	hexcurse
PORTVERSION=	1.60.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Versatile ncurses-based hex editor
WWW=		https://BSDforge.com/projects/editors/hexcurse/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	LonnyGomes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/hexcurse share/man/man1/hexcurse.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=deprecated-non-prototype
.endif

CFLAGS+=	-Wno-error=format-truncation

.include <bsd.port.post.mk>
