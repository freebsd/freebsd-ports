# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xapian
PORTVERSION=	1.4.15
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

CONFLICTS_INSTALL=	xapian-bindings12

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||g' ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 2.6
BUILD_DEPENDS+=	rubygem-rdoc>=0:devel/rubygem-rdoc
.endif

.include <bsd.port.post.mk>
