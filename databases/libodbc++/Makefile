# New ports collection makefile for:	libodbc++
# Date created:		26 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libodbc++
PORTVERSION=	0.2.3
PORTREVISION=	7
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libodbcxx

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A C++ class library and toolset for ODBC access to data sources

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-isqlxx
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"
CXXFLAGS+=	${PTHREAD_CFLAGS}

# libodbc++ needs an ODBC driver manager to be installed, and it supports
# both iODBC and unixODBC.

.if defined(WITH_IODBC) && defined(WITH_UNIXODBC)
IGNORE=		selected mutually exclusive options: WITH_IODBC and WITH_UNIXODBC
.endif

.if !defined(WITH_IODBC) && !defined(WITH_UNIXODBC)
WITH_UNIXODBC?=	yes
.endif

.if defined(WITH_IODBC)
LIB_DEPENDS=	iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc=${LOCALBASE}
.elif defined(WITH_UNIXODBC)
LIB_DEPENDS=	odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}
.endif

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	INSTALL progref

.ifdef NOPORTDOCS
post-patch:
	${REINPLACE_CMD} '/install-data-am:/s/install-data-local//' \
		${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} '/install-data-am:/s/install-data-local//' \
		${WRKSRC}/doc/progref/Makefile.in
.endif

.include <bsd.port.mk>
