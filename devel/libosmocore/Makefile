# $FreeBSD$

PORTNAME=	libosmocore
PORTVERSION=	0.6.6
CATEGORIES=	devel
MASTER_SITES=	http://chaosophia.net/downloads/osmocom/${PORTNAME}/ \
		http://ns1.chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Common library for all Osmocom projects

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	aclocal autoconf automake libtoolize autoheader
AUTOMAKE_ARGS=	--gnu --add-missing --copy

USES=		gmake libtool
LDFLAGS+=	-lexecinfo
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		dot:${PORTSDIR}/graphics/graphviz

post-patch:
	${REINPLACE_CMD} -e 's|pkgconfigdir.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in codec core gsm vty
	${FIND} ${WRKSRC}/doc/${i}/html -not -type d | ${SED} \
	  's,^${WRKSRC}/doc/${i}/html,${DOCSDIR_REL}/${i}/html,' >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
