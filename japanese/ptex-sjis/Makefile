# New ports collection makefile for:	pTeX-sjis
# Date created:		05 Oct 1997
# Whom:			max
#
# $FreeBSD$
#

PORTNAME=	ptex
PORTVERSION=	2.1.11
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-sjis
DISTNAME=	ptex-src-2.1.10
DIST_SUBDIR=	teTeX/ptex

MAINTAINER=	max@FreeBSD.org

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	ptex2.1.10-11.patch

BUILD_DEPENDS=	${PREFIX}/share/texmf/ptex/plain/base/ptex.tex:${PORTSDIR}/japanese/ptex-common
RUN_DEPENDS=	${PREFIX}/share/texmf/ptex/plain/base/ptex.tex:${PORTSDIR}/japanese/ptex-common

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	sjis
WRKSRC=	${WRKDIRPREFIX}${.CURDIR}/../ptex-common/work/teTeX-1.0/texk/web2c/${SRCDIR}
ALL_TARGET=	default

SRCDIR=		ptex-src-2.1.10
BINARIES=	ptex pdvitype jbibtex pltotf tftopl

pre-extract:
.if !exists(${WRKDIRPREFIX}${.CURDIR}/../ptex-common/work/.build_done)
	@(cd ${.CURDIR}/../ptex-common; \
	  ${SETENV} ${MAKE_ENV} ${MAKE})
.endif

post-extract:
	@${RM} -rf ${WRKSRC}
	@${MV} ${WRKDIR}/${SRCDIR} ${WRKDIRPREFIX}${.CURDIR}/../ptex-common/work/teTeX-1.0/texk/web2c

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.for bin in ${BINARIES}
	@/usr/bin/strip ${PREFIX}/bin/${bin}
.endfor
	@${LN} -sf ptex ${PREFIX}/bin/platex
	@${PREFIX}/bin/mktexlsr ${PREFIX}/share/texmf

pre-clean:
	@${RM} -rf ${WRKSRC}

.include <bsd.port.mk>
