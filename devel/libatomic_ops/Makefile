# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libatomic_ops
DISTVERSION=	7.3alpha2
CATEGORIES=	devel
MASTER_SITES=	http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Atomic operations access library

LICENSE=	BSD GPLv2
LICENSE_COMB=	multi

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
# Inhibit installation of extra copy of GPL
	@${REINPLACE_CMD} -E 's,: (un)?install-dist_pkgdataDATA,:,' \
		${WRKSRC}/Makefile.in
.if ${PORT_OPTIONS:MDOCS}
# Fix documentation installation directory
	@${REINPLACE_CMD} -e 's,pkgdata,pkgdoc,g ; s,(datadir.*,(docdir),' \
		${WRKSRC}/doc/Makefile.in
.else
# If documentation is not wanted, just disable it instead of fixing
	@${REINPLACE_CMD} -E 's,: (un)?install-dist_pkgdataDATA,:,' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
