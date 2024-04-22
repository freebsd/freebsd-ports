PORTNAME=	ocrad
DISTVERSION=	0.29
CATEGORIES=	graphics
MASTER_SITES=	GNU

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OCR program implemented as filter
WWW=		https://www.gnu.org/software/ocrad/ocrad.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng16.so:graphics/png

USES=		localbase:ldflags tar:lz
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} CXX="${CXX}" CXXFLAGS="${CXXFLAGS} -fPIC" --mandir=${PREFIX}/share/man --infodir=${PREFIX}/info

MAKE_ARGS=	LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/${PORTNAME} \
		include/ocradlib.h \
		lib/libocrad.so \
		info/ocrad.info \
		share/man/man1/ocrad.1.gz

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
