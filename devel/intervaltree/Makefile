PORTNAME=	intervaltree
DISTVERSION=	0.1-2
DISTVERSIONSUFFIX=	-gaa59377
CATEGORIES=	devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Minimal C++ interval tree implementation
WWW=		https://github.com/ekg/intervaltree

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	ekg

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/interval_tree_test include/${PORTNAME}/IntervalTree.h

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
post-patch:
	${REINPLACE_CMD} -e 's|<bool, unsigned long>|<bool, unsigned int>|g' \
		${WRKSRC}/interval_tree_test.cpp
.endif

.include <bsd.port.post.mk>
