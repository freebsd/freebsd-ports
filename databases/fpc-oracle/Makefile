# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			28 November 2001
# Whom: 				John Merryweather Cooper et al
#
# $FreeBSD$
#

PORTNAME=	oracle
PORTVERSION=	1.0.10
CATEGORIES=	databases lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freepascal
PKGNAMEPREFIX=	fpc-
DISTNAME=	fpc-${PORTVERSION}.ELF
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Pascal interface to Oracle

.include <bsd.port.pre.mk>

ORACLE7_LIB=	${LOCALBASE}/oracle7/rdbms/lib
BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		${ORACLE7_LIB}/libnlsrtl3.a:${PORTSDIR}/databases/oracle7-client
RUN_DEPENDS=	${BUILD_DEPENDS}
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif
.if ${OSVERSION} < 470000
EXTRACT_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar
TAR=			${LOCALBASE}/bin/gtar
.endif
USE_GMAKE=	yes
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
# postgres sources
	@${TAR} zxf ${WRKSRC}/sources/unitsoraclesrc.tar.gz \
		--directory ${WRKSRC}

post-patch:
# change to alter amount of optimization
	@${FIND} ${WRKSRC}/share/src/fpc-${PORTVERSION} -name \
		"Makefile*" | ${XARGS} ${REINPLACE_CMD} 's|-OG2p3|-OG2p1|g'

	${REINPLACE_CMD} 's|/usr/local/oracle8cli/lib|${ORACLE7_LIB}|g' \
		${WRKSRC}/share/src/fpc-${PORTVERSION}/packages/base/oracle/Makefile.fpc

do-build:
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/packages/base/oracle && \
		${GMAKE} ${MAKE_ENV} all

do-install:
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/packages/base/oracle && \
		${GMAKE} ${MAKE_ENV} install

.include <bsd.port.post.mk>
