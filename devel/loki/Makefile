# Created by: Sun Chang-Ming
# $FreeBSD$

PORTNAME=	loki
PORTVERSION=	0.1.7
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}-lib/Loki/Loki%20${PORTVERSION}

MAINTAINER=	snnn119@gmail.com
COMMENT=	C++ library of common design patterns

USES=		gmake dos2unix
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

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
