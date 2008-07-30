# New ports collection makefile for:	kbuild
# Date created:		Mon Jul 28 14:34:33 BST 2008
# Whom:			Bruce Simpson
#
# $FreeBSD$
#

PORTNAME=	kBuild
PORTVERSION=	0.1.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netlabs.org/pub/kbuild/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Makefile framework

# XXX: This case is not handled by USE_AUTOTOOLS as kmk bootstrap involves
# running these directly.
BUILD_DEPENDS=	automake-1.9:${PORTSDIR}/devel/automake19 \
		autoconf-2.62:${PORTSDIR}/devel/autoconf262

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes

do-build:
	cd ${WRKSRC} && ${SETENV} ACLOCAL=aclocal-1.9 AUTOMAKE=automake-1.9 AUTORECONF=autoreconf-2.62 ./kBuild/env.sh --full ${GMAKE} -f bootstrap.gmk
	cd ${WRKSRC} && ${RM} -rf out
	cd ${WRKSRC} && ./kBuild/env.sh kmk
	cd ${WRKSRC} && ./kBuild/env.sh kmk NIX_INSTALL_DIR=${PREFIX} BUILD_TYPE=release -C ${WRKSRC}

do-install:
	(cd ${WRKSRC}/out/freebsd.${MACHINE_ARCH}/release${PREFIX}/bin && ${COPYTREE_BIN} \* ${PREFIX}/bin)
	${MKDIR) ${DATADIR}
	(cd ${WRKSRC}/out/freebsd.${MACHINE_ARCH}/release${PREFIX}/share/kBuild && ${COPYTREE_SHARE} \* ${DATADIR})

.include <bsd.port.mk>
