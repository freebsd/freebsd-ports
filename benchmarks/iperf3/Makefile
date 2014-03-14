# Created by: Bruce A. Mah <bmah@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iperf
PORTVERSION=	3.0.2
CATEGORIES=	benchmarks ipv6
MASTER_SITES=	http://stats.es.net/software/
PKGNAMESUFFIX=	3

MAINTAINER=	bmah@FreeBSD.org
COMMENT=	Improved tool to measure TCP and UDP bandwidth

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool

# Set ${DOCSDIR} to avoid conflict with benchmarks/iperf ${DOCSDIR}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

PLIST_FILES=	bin/iperf3 \
		include/iperf_api.h \
		lib/libiperf.a \
		lib/libiperf.la \
		lib/libiperf.so \
		lib/libiperf.so.0 \
		lib/libiperf.so.0.0.0 \
		man/man1/iperf3.1.gz \
		man/man3/libiperf.3.gz
PORTDOCS=	*

post-patch:
# automake generates a buggy Makefile.in that tries to do ${RANLIB} on
# libiperf3.a after installing with mode 444; this breaks staging.
# Since ${RANLIB} was already run on the library, this broken
# invocation was redundant, and can be eliminated.  The fix below is
# based on the solution for a similar situation for an unrelated port
# in r339298.
	@${REINPLACE_CMD} -e '/echo.*RANLIB/,+1d' ${WRKSRC}/src/Makefile.in
# Don't build stuff that we're not going to install.  Among other
# things this means we're not going to try to build profiled objects
# and/or executables.
	@${REINPLACE_CMD} -e '/^PROGRAMS /s/\$$(noinst_PROGRAMS)//' ${WRKSRC}/src/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS README.md RELEASE_NOTES TODO ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
