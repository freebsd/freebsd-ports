# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			8 January 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	odbc
PORTVERSION=	1.0.10
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/FreeBSD/ \
		http://planetmirror.com/pub/fpc/dist/FreeBSD/ \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/FreeBSD/ \
		ftp://freepascal.stack.nl/pub/fpc/dist/FreeBSD/ \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/FreeBSD/ \
		ftp://ftp.us.freepascal.org/pub/fpc/dist/FreeBSD/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freepascal
PKGNAMEPREFIX=	fpc-
DISTNAME=	fpc-${PORTVERSION}.ELF
EXTRACT_SUFX=	.tar

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	Free Pascal interface to ODBC

.include <bsd.port.pre.mk>

LIB_DEPENDS=	odbc.1:${PORTSDIR}/databases/unixODBC
BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
RUN_DEPENDS=	${BUILD_DEPENDS}
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=   c.4:${PORTSDIR}/misc/compat4x
.endif
.if ${OSVERSION} < 470000
EXTRACT_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar
TAR=			${LOCALBASE}/bin/gtar
.endif
USE_GMAKE=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAKE_ENV+=	PATH=${LOCALBASE}/bin:$$PATH \
		FPC=${LOCALBASE}/bin/ppc386 \
		INSTALL_BASEDIR=${PREFIX}/lib/fpc/${PORTVERSION} \
		INSTALL_BINDIR=${PREFIX}/bin \
		GCCLIBDIR=/usr/lib \
		RELEASE=1

do-extract:
# unpack distribution
	@${MKDIR} ${WRKSRC}
	@${TAR} xf ${DISTDIR}/${DISTNAME}.tar --directory ${WRKSRC}
# unpack sources distribution
	@${MKDIR} ${WRKSRC}/sources
	@${TAR} xf ${WRKSRC}/sources.tar --directory ${WRKSRC}/sources
# further extract base sources
#
# odbc sources
	@${TAR} zxf ${WRKSRC}/sources/unitsodbcsrc.tar.gz \
		--directory ${WRKSRC}

post-patch:
# change to alter amount of optimization
	@${FIND} ${WRKSRC}/share/src/fpc-${PORTVERSION} -name \
		"Makefile*" | ${XARGS} ${REINPLACE_CMD} 's|-OG2p3|-OG2p1|g'

do-build:
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/packages/base/odbc && \
		${GMAKE} ${MAKE_ENV} all

do-install:
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/packages/base/odbc && \
		${GMAKE} ${MAKE_ENV} install

.include <bsd.port.post.mk>
