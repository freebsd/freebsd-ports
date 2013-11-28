# $FreeBSD$

PORTNAME=	libhtp
PORTVERSION=	0.5.9
CATEGORIES=	devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Security-aware parser for the HTTP protocol

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	ironbee
GH_COMMIT=	f5f3c5c

USES=		pkgconfig pathfix iconv
USE_AUTOTOOLS=	libtool autoheader aclocal
ACLOCAL_ARGS=	-Im4
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		${ICONV_LIB}

CONFLICTS_INSTALL=	libhtp-suricata-*

pre-configure:
	@${REINPLACE_CMD} -Ee 's,^(pkgconfigdir = ).*,\1$$(exec_prefix)/libdata/pkgconfig,' ${WRKSRC}/Makefile.am
	@cd ${WRKSRC} && ${SH} ./autogen.sh

regression-test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
