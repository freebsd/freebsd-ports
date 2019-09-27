# Created by: Ulrich Spoerlein <q@uni.de>
# $FreeBSD$

PORTNAME=	ocrad
DISTVERSION=	0.27
CATEGORIES=	graphics
MASTER_SITES=	GNU

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OCR program implemented as filter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:lz
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} CXX="${CXX}" CXXFLAGS="${CXXFLAGS} -fPIC" --mandir=${PREFIX}/man --infodir=${PREFIX}/info
USE_LDCONFIG=	yes

PLIST_FILES=	bin/${PORTNAME} \
		include/ocradlib.h \
		lib/libocrad.so \
		man/man1/ocrad.1.gz \
		info/ocrad.info

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	AUTHORS ChangeLog NEWS README
PORTEXAMPLES=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	cd ${WRKSRC}/testsuite && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
