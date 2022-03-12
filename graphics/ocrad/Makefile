# Created by: Ulrich Spoerlein <q@uni.de>

PORTNAME=	ocrad
DISTVERSION=	0.28
CATEGORIES=	graphics
MASTER_SITES=	GNU

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OCR program implemented as filter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng16.so:graphics/png

USES=		localbase:ldflags tar:lz
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} CXX="${CXX}" CXXFLAGS="${CXXFLAGS} -fPIC" --mandir=${PREFIX}/man --infodir=${PREFIX}/info

MAKE_ARGS=	LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/${PORTNAME} \
		include/ocradlib.h \
		lib/libocrad.so \
		man/man1/ocrad.1.gz \
		info/ocrad.info

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	AUTHORS ChangeLog NEWS README
PORTEXAMPLES=	*

post-install: # strip
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/ocrad \
		${STAGEDIR}${PREFIX}/lib/libocrad.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	cd ${WRKSRC}/testsuite && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
