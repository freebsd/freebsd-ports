# New ports collection makefile for:	Free Pascal ibase Unit
# Date created: 			9 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	ibase
PORTVERSION=	1.0.10
CATEGORIES=	databases lang
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
COMMENT=	Free Pascal interface to interbase

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 470000
EXTRACT_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
TAR=			${LOCALBASE}/bin/gtar
.endif
USE_GMAKE=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

PLIST_SUB+=	INSTDIR=lib/fpc/${PORTVERSION}/units/freebsd/ibase \
		PORTVERSION=${PORTVERSION}

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
# interbase sources
	@${TAR} zxf ${WRKSRC}/sources/unitsibasesrc.tar.gz \
		--directory ${WRKSRC}

post-patch:
# change to alter amount of optimization
	@${FIND} ${WRKSRC}/share/src/fpc-${PORTVERSION} -name \
		"Makefile*" | ${XARGS} ${REINPLACE_CMD} 's|-OG2p3|-OG2p1|g'

do-build:
	@${SETENV} ${MAKE_ENV} ${GMAKE} -C \
		${WRKSRC}/share/src/fpc-${PORTVERSION}/packages/base/ibase \
		all

do-install:
	@${SETENV} ${MAKE_ENV} ${GMAKE} -C \
		${WRKSRC}/share/src/fpc-${PORTVERSION}/packages/base/ibase \
		install

.include <bsd.port.post.mk>
