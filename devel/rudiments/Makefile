# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rudiments
PORTVERSION=	0.41
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.50

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class library for daemons, clients, servers, and more

LICENSE=	LGPL20

OPTIONS_DEFINE=	DOCS

USES=		pkgconfig
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-ssl-includes=-I${OPENSSLINC} \
		--with-ssl-libs=-L${OPENSSLLIB} \
		--disable-pcre
USE_LDCONFIG=	yes

MAN1=		rudiments-config.1

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/cd doc;/s|^|#| ; \
		 /pkgconfig/s|$$(libdir)/|$$(prefix)/libdata/|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|' ${WRKSRC}/doc/programming/insert.pl
	@${REINPLACE_CMD} -e \
		's| -release $$(RUDIMENTS_VERSION)||' ${WRKSRC}/src/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif

.include <bsd.port.mk>
