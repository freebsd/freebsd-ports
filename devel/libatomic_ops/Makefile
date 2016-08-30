# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libatomic_ops
PORTVERSION=	7.4.4
CATEGORIES=	devel
MASTER_SITES=	http://www.hboehm.info/gc/gc_source/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Atomic operations access library

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix

OPTIONS_DEFINE=	DOCS

post-patch:
# Inhibit installation of extra copy of GPL
	@${REINPLACE_CMD} -E 's,: (un)?install-dist_pkgdataDATA,:,' \
		${WRKSRC}/Makefile.in

post-patch-DOCS-on:
# Fix documentation installation directory
	@${REINPLACE_CMD} -e 's,pkgdata,pkgdoc,g ; s,(datadir.*,(docdir),' \
		${WRKSRC}/doc/Makefile.in

post-patch-DOCS-off:
# If documentation is not wanted, just disable it instead of fixing
	@${REINPLACE_CMD} -E 's,: (un)?install-dist_pkgdataDATA,:,' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
