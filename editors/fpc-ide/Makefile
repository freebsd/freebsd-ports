# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			28 November 2001
# Whom: 				John Merryweather Cooper et al
#
# $FreeBSD$
#

PORTNAME=	ide
PORTVERSION=	1.0.10
CATEGORIES=	editors lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freepascal
PKGNAMEPREFIX=	fpc-
DISTNAME=	fpc-${PORTVERSION}.ELF
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Pascal integrated IDE/compiler

.include <bsd.port.pre.mk>

BUILD_DEPENDS+=	ppc386:${PORTSDIR}/lang/fpc \
		${LOCALBASE}/lib/fpc/${PORTVERSION}/units/freebsd/gdbint/gdbint.ppu:${PORTSDIR}/devel/fpc-gdbint \
		${LOCALBASE}/lib/fpc/${PORTVERSION}/units/freebsd/fv/drivers.ppu:${PORTSDIR}/devel/fpc-fvision
RUN_DEPENDS+=	${BUILD_DEPENDS}
.if ${OSVERSION} < 470000
EXTRACT_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
TAR=			${LOCALBASE}/bin/gtar
.endif
USE_GMAKE=	yes
ONLY_FOR_ARCHS=	i386

DOCSDIR=	${PREFIX}/share/doc/fpc
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAKE_ENV+=	PATH=${LOCALBASE}/bin:$$PATH \
		FPC=${LOCALBASE}/bin/ppc386 \
		INSTALL_BASEDIR=${PREFIX}/lib/fpc/${PORTVERSION} \
		INSTALL_BINDIR=${PREFIX}/bin \
		INSTALL_DOCDIR=${DOCSDIR} \
		GCCLIBDIR=/usr/lib \
		GDBLIBDIR=${LOCALBASE}/lib/fpc/${PORTVERSION}/units/freebsd/gdbint/libgdb \
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
# ide and compiler sources
	@${TAR} zxf ${WRKSRC}/sources/compilersrc.tar.gz \
		--directory ${WRKSRC}
	@${TAR} zxf ${WRKSRC}/sources/idesrc.tar.gz \
		--directory ${WRKSRC}

post-patch:
# change to alter amount of optimization
	@${FIND} ${WRKSRC}/share/src -name "Makefile*" | \
		${XARGS} ${REINPLACE_CMD} 's|-OG2p3|-OG2p1|g'

pre-build:
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/ide/compiler && \
		fpcmake

do-build:
	@${SETENV} ${MAKE_ENV} ${GMAKE} -C \
		${WRKSRC}/share/src/fpc-${PORTVERSION}/ide \
		all

do-install:
	@${SETENV} ${MAKE_ENV} ${GMAKE} -C \
		${WRKSRC}/share/src/fpc-${PORTVERSION}/ide \
		install

.include <bsd.port.post.mk>
