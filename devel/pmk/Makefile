# New ports collection makefile for:	pmk
# Date created:		October 13, 2003
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pmk
PORTVERSION=	0.10.4
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Pre Make Kit, a sane replacement for autoconf

PKGINSTALL=	${WRKDIR}/pkg-install

MAN1=	pmk.1 pmkscan.1 pmkinstall.1 pmkpc.1
MAN5=	pmk.conf.5 pmkfile.5 pmksyntax.5 scanfile.5
MAN8=	pmksetup.8

do-configure:
	cd ${WRKSRC}; SYSCONFDIR=${PREFIX}/etc ./pmkcfg.sh

post-build:
	@${CAT} ${PKGDIR}/pkg-install | ${SED} -e 's,%%PREFIX%%,${PREFIX},g' > ${PKGINSTALL}

post-install:
	@${TRUE}
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
