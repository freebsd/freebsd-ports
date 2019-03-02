# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xapian
PORTVERSION=	1.4.11
DISTVERSIONPREFIX=	bindings-
CATEGORIES=	databases ruby
MASTER_SITES=	https://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding for Xapian

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xapian-core>=${PORTVERSION}:databases/xapian-core
LIB_DEPENDS=	libxapian.so:databases/xapian-core

CONFLICTS_INSTALL=	xapian-bindings12

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang libtool tar:xz
USE_RUBY=	yes

CONFIGURE_ARGS=	--datarootdir=${DATADIR} \
		--docdir=${DOCSDIR} \
		--enable-shared \
		--enable-static \
		--with-ruby \
		--without-csharp \
		--without-java \
		--without-lua \
		--without-perl \
		--without-php \
		--without-php7 \
		--without-python \
		--without-python3 \
		--without-tcl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++11

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||g' ${WRKSRC}/configure

.include <bsd.port.mk>
