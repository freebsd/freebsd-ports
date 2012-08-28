# New ports collection makefile for:   libhtp
# Date created:        19 December 2011
# Whom:                wxs@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libhtp
PORTVERSION=	0.3.0
CATEGORIES=	devel
#MASTER_SITES=	# This port uses github

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Security-aware parser for the HTTP protocol

USE_GITHUB=	yes
GH_ACCOUNT=	ironbee
GH_COMMIT=	a334539

USE_AUTOTOOLS=	libtool autoheader aclocal
ACLOCAL_ARGS=	-Im4
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig gnomehack
USE_ICONV=	yes

pre-configure:
	@${REINPLACE_CMD} -Ee 's,^(pkgconfigdir = ).*,\1$$(exec_prefix)/libdata/pkgconfig,' ${WRKSRC}/Makefile.am
	@cd ${WRKSRC} && ${SH} ./autogen.sh

.include <bsd.port.mk>
