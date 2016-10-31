# Created by: Bruce A. Mah <bmah@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iperf
PORTVERSION=	3.1.4
CATEGORIES=	benchmarks ipv6
MASTER_SITES=	http://downloads.es.net/pub/iperf/
PKGNAMESUFFIX=	3

MAINTAINER=	bmah@FreeBSD.org
COMMENT=	Improved tool to measure TCP and UDP bandwidth

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi

GNU_CONFIGURE=	yes
USES=		libtool
USE_LDCONFIG=	yes

PORTDOCS=	README.md RELEASE_NOTES

# Set ${DOCSDIR} to avoid conflict with benchmarks/iperf ${DOCSDIR}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

post-patch:
# Don't build stuff that we're not going to install.  Among other
# things this means we're not going to try to build profiled objects
# and/or executables.
	@${REINPLACE_CMD} -e '/^PROGRAMS /s/\$$(noinst_PROGRAMS)//' ${WRKSRC}/src/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
