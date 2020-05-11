# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xapian
PORTVERSION=	1.4.15
DISTVERSIONPREFIX=	bindings-
CATEGORIES=	databases python
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding for Xapian

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xapian-core>=${PORTVERSION}:databases/xapian-core
LIB_DEPENDS=	libxapian.so:databases/xapian-core

USES=		compiler:c++11-lang libtool python tar:xz

CONFIGURE_ARGS=	--datarootdir=${DATADIR} \
		--docdir=${DOCSDIR} \
		--enable-shared \
		--enable-static \
		--without-csharp \
		--without-java \
		--without-lua \
		--without-perl \
		--without-php \
		--without-php7 \
		--without-ruby \
		--without-tcl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++11
USE_PYTHON=	flavors

PORTDOCS=	*

CONFLICTS_INSTALL=	xapian-bindings12

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PY_SPHINX}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 3000
CONFIGURE_ARGS+=--with-python3 \
		--without-python
CONFIGURE_ENV+=	PYTHON3=${PYTHON_CMD}
.else
CONFIGURE_ARGS+=--with-python \
		--without-python3
CONFIGURE_ENV+=	PYTHON2=${PYTHON_CMD}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||g' ${WRKSRC}/configure

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's| all-local||; s| install-data-local install-dist_exampledataDATA||' ${WRKSRC}/python/Makefile.in ${WRKSRC}/python3/Makefile.in

.include <bsd.port.post.mk>
