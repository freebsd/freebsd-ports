# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rudiments
PORTVERSION=	0.44
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class library for daemons, clients, servers, and more

LICENSE=	LGPL20

OPTIONS_DEFINE=	DOCS PCRE SSL
OPTIONS_DEFAULT=SSL

PCRE_LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
PCRE_CONFIGURE_ENABLE=	pcre

SSL_USE=	OPENSSL=yes
SSL_CONFIGURE_ENABLE=	ssl
SSL_CONFIGURE_ON=	--with-ssl-includes=-I${OPENSSLINC} \
			--with-ssl-libs=-L${OPENSSLLIB}

USES=		pkgconfig shebangfix
SHEBANG_FILES=	doc/programming/insert.pl
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} ${REINPLACE_CMD} -e \
		'/pkgconfig/s| $$(libdir)/| $${DESTDIR}$$(prefix)/libdata/| ; \
		 /INSTALL/s| $$(bindir)| $${DESTDIR}$$(bindir)| ; \
		 /INSTALL/s| $$(docdir)| $${DESTDIR}$$(docdir)| ; \
		 /INSTALL/s| $$(includedir)| $${DESTDIR}$$(includedir)| ; \
		 /INSTALL/s| $$(mandir)| $${DESTDIR}$$(mandir)| ; \
		 /INSTALL/s| $$(libdir)| $${DESTDIR}$$(libdir)| ; \
		 /finish/s| $$(libdir)| $${DESTDIR}$$(libdir)|'

.include <bsd.port.mk>
