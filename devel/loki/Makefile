PORTNAME=	loki
PORTVERSION=	0.1.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}-lib/Loki/Loki%20${PORTVERSION}

MAINTAINER=	snnn119@gmail.com
COMMENT=	C++ library of common design patterns
WWW=		https://sourceforge.net/projects/loki-lib/

BROKEN=		error: a template argument list is expected after a name prefixed by the template keyword
DEPRECATED=	dead upstream, sole consumer removed from tree long ago
EXPIRATION_DATE=	2026-03-31

USES=		gmake dos2unix
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

CXXFLAGS+=	-Wno-return-type

DOCS=		README CHANGES doc/flex/flex_string.html \
		doc/yasli/Notes.txt \
		doc/yasli/yasli.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's/bad_function_call/Loki::bad_function_call/g' \
		${WRKSRC}/test/Function/FunctionTest.cpp
	@${REINPLACE_CMD} -e '/CXXWARNFLAGS/s/$$/ ${CXXFLAGS}/g' \
		-e 's/\$${PREFIX}/$${DESTDIR}$${PREFIX}/g' \
		${WRKSRC}/Makefile.common

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
