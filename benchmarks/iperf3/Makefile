PORTNAME=	iperf
DISTVERSION=	3.19.1
CATEGORIES=	benchmarks
MASTER_SITES=	https://github.com/esnet/${PORTNAME}/releases/download/${DISTVERSION}/ \
		https://downloads.es.net/pub/${PORTNAME}/
PKGNAMESUFFIX=	3

MAINTAINER=	bmah@FreeBSD.org
COMMENT=	Improved tool to measure TCP and UDP bandwidth
WWW=		https://software.es.net/iperf/

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		cpe libtool ssl
CPE_VENDOR=	iperf_project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
PORTDOCS=	README.md RELNOTES.md

# Set ${DOCSDIR} to avoid conflict with benchmarks/iperf
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

OPTIONS_DEFINE=	DOCS STATIC
OPTIONS_SUB=	yes

STATIC_CONFIGURE_ENABLE=	static

post-patch:
# Don't build stuff that we're not going to install.  Among other
# things this means we're not going to try to build profiled objects
# and/or executables.
	@${REINPLACE_CMD} -e '/^PROGRAMS /s/\$$(noinst_PROGRAMS)//' ${WRKSRC}/src/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
