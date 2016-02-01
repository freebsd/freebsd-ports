# Created by: ache
# $FreeBSD$

PORTNAME=	hpack
PORTVERSION=	0.79a
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.franken.de/pub/crypt/misc/ \
		http://ftp.tugraz.at/mirror/crypto/programs/hpack/
DISTNAME=	hpack79src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-System Archiver with open keys PGP-based security

USES=		alias ncurses
USE_CSTD=	gnu89
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	freebsd
MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX}
INSTALL_TARGET=	freebsd.install

post-patch:
.for f in language/language.c cli.c
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/${f}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/hpack.cfg ${STAGEDIR}${PREFIX}/etc/hpack.cfg.sample

.include <bsd.port.mk>
