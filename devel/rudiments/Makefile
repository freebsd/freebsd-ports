# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rudiments
PORTVERSION=	0.43
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class library for daemons, clients, servers, and more

LICENSE=	LGPL20

OPTIONS_DEFINE=	DOCS

USES=		pkgconfig shebangfix
SHEBANG_FILES=	doc/programming/insert.pl
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-ssl-includes=-I${OPENSSLINC} \
		--with-ssl-libs=-L${OPENSSLLIB} \
		--disable-pcre
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/pkgconfig/s|$$(libdir)/|$$(prefix)/libdata/|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's| -release $$(RUDIMENTS_VERSION)||' \
		-e 's|-rpath $$(libdir)|-rpath ${PREFIX}/lib|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
