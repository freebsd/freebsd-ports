# Created by: Ulrich Spoerlein <q@uni.de>
# $FreeBSD$

PORTNAME=	ocrad
PORTVERSION=	0.26
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNU
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OCR program implemented as filter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

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
