# $FreeBSD$

PORTNAME=	libhtp
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	devel
#MASTER_SITES=	# This port uses github

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Security-aware parser for the HTTP protocol

USE_GITHUB=	yes
GH_ACCOUNT=	ironbee
GH_COMMIT=	a334539

USE_AUTOTOOLS=	libtool autoheader aclocal
ACLOCAL_ARGS=	-Im4
USE_LDCONFIG=	yes
USES=		pkgconfig pathfix iconv

CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		${ICONV_LIB}

CONFLICTS_INSTALL=	libhtp-suricata-*

NO_STAGE=	yes
pre-configure:
	@${REINPLACE_CMD} -Ee 's,^(pkgconfigdir = ).*,\1$$(exec_prefix)/libdata/pkgconfig,' ${WRKSRC}/Makefile.am
	@cd ${WRKSRC} && ${SH} ./autogen.sh

.include <bsd.port.mk>
