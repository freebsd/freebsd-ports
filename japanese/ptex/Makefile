# New ports collection makefile for:	pTeX-euc
# Version required:	2.1.5
# Date created:		05 Oct 1997
# Whom:			max
#
# $Id: Makefile,v 1.1.1.1 1997/10/04 17:20:30 max Exp $
#

DISTNAME=	ptex215
PKGNAME=	ja-ptex-euc-2.1.5
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex215/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} plib13-euc.tar.gz

MAINTAINER=	max@FreeBSD.ORG

RUN_DEPENDS=	ptex-common:${PORTSDIR}/japanese/ptex-common

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	euc
WRKSRC=		${.CURDIR}/../ptex-common/work/web2c-7.0/web2c/${DISTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
ALL_TARGET=	default

BINARIES=	iniptex jbibtex pdvitype pltotf ptex tftopl virptex

pre-extract:
.if !exists(${.CURDIR}/../ptex-common/work/.build_done)
	@(cd ${.CURDIR}/../ptex-common; \
	  ${SETENV} ${MAKE_ENV} ${MAKE})
.endif

post-extract:
	@${RM} -rf ${WRKSRC}
	@${MV} ${WRKDIR}/${DISTNAME} ${.CURDIR}/../ptex-common/work/web2c-7.0/web2c

pre-install:
	@${EXTRACT_CMD} -C ${PREFIX} -zxf ${DISTDIR}/plib13-euc.tar.gz

post-install:
.for bin in ${BINARIES}
	@strip ${PREFIX}/bin/${bin}
.endfor

pre-clean:
	@${RM} -rf ${WRKSRC}

.include <bsd.port.mk>
