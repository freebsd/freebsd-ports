# New ports collection makefile for:	dserver
# Date created:		3 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dserver
PORTVERSION=	2.2.2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.pu-toyama.ac.jp/pub/misc/ \
		ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/ \
		ftp://ftp.sra.co.jp/pub/net/ndtp/misc/
DISTNAME=	${PORTNAME}2.2betapl2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}.addtable.${EXTRACT_SUFX} \
		kenjiro-ndtpd.diff \
		kenjiro-dictlist.diff
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}.addtable.${EXTRACT_SUFX}

MAINTAINER=	mita@jp.FreeBSD.org

RUN_DEPENDS=	jless:${PORTSDIR}/japanese/less

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes

pre-patch:
	${PATCH} -d ${WRKSRC}/clients -E  < ${DISTDIR}/kenjiro-ndtpd.diff
	${PATCH} -d ${WRKSRC}/clients -E  <  ${DISTDIR}/kenjiro-dictlist.diff

post-install:
	@${SED} s!PREFIX_DIR!${PREFIX}!g ${WRKSRC}/setup.sh.template \
	  > ${PREFIX}/lib/dserver/setup.sh
	@${SED} s!PREFIX_DIR!${PREFIX}!g ${WRKSRC}/deinstall.sh.template \
	  > ${PREFIX}/lib/dserver/deinstall.sh
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD-setup.euc ${PREFIX}/lib/dserver/doc/
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

.include <bsd.port.mk>
