# New ports collection makefile for:	pTeX-sjis
# Date created:		05 Oct 1997
# Whom:			max
#
# $FreeBSD$
#

PORTNAME=	ptex
PORTVERSION=	2.1.10
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-sjis
DISTNAME=	ptex-src-2.1.9-1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		  ${PTEX_PATCHFILES}
DIST_SUBDIR=	teTeX/ptex
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	max@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/texmf/ptex/plain/base/ptex.tex:${PORTSDIR}/japanese/ptex-common
RUN_DEPENDS=	${LOCALBASE}/share/texmf/ptex/plain/base/ptex.tex:${PORTSDIR}/japanese/ptex-common

MANUAL_PACKAGE_BUILD=	incompatible with other versions of ptex-*
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	sjis
WRKSRC=	${WRKDIRPREFIX}${.CURDIR}/../ptex-common/work/teTeX-1.0/texk/web2c/${SRCDIR}
ALL_TARGET=	default

SRCDIR=		ptex-src-2.1.9
PTEX_PATCHFILES=	ptex2.1.9-10.patch ptex2.1.9-10_2.patch \
			pltotf1.3-4.patch
BINARIES=	ptex pdvitype jbibtex pltotf tftopl

pre-extract:
.if !exists(${WRKDIRPREFIX}${.CURDIR}/../ptex-common/work/.build_done)
	@(cd ${.CURDIR}/../ptex-common; \
	  ${SETENV} ${MAKE_ENV} ${MAKE})
.endif

post-extract:
	@${RM} -rf ${WRKSRC}
	@${MV} ${WRKDIR}/${SRCDIR} ${WRKDIRPREFIX}${.CURDIR}/../ptex-common/work/teTeX-1.0/texk/web2c

do-patch:
.for f in ${PTEX_PATCHFILES}
	@/usr/bin/uudecode -p ${DISTDIR}/${DIST_SUBDIR}/$f | \
	  ${PATCH} ${PATCH_DIST_ARGS}
.endfor

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
