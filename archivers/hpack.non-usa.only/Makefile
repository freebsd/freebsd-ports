# New ports collection makefile for:    hpack.with_encryption
# Date created:         7 Jan 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	hpack
PORTVERSION=	0.79a
CATEGORIES=	archivers
MASTER_SITES=   ftp://src.doc.ic.ac.uk/Mirrors/sunsite.doc.ic.ac.uk/hpack/
DISTNAME=	hpack79src

MAINTAINER=	ache@FreeBSD.org

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	freebsd
INSTALL_TARGET= freebsd.install
MAN1=		hpack.1
USE_REINPLACE=	yes

post-patch:
.for f in language/language.c cli.c
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/${f}
.endfor

post-install:
	@${CP} ${WRKSRC}/docs/hpack.cfg ${PREFIX}/etc/hpack.cfg.dist

.include <bsd.port.mk>
