# New ports collection makefile for:	dserver
# Version required:	2.2betapl2
# Date created:		3 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.5 1997/09/12 05:57:53 asami Exp $
#

DISTNAME=	dserver2.2betapl2
PKGNAME=	ja-dserver-2.2.2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.pu-toyama.ac.jp/pub/misc/ \
		ftp://ports.jp.FreeBSD.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/
DISTFILES=	dserver2.2betapl2.tar.gz dserver2.2betapl2.addtable.tar.gz \
		diclookup-mule-2.3.0.add.tar.gz

MAINTAINER=	mita@jp.FreeBSD.org

RUN_DEPENDS=	jless:${PORTSDIR}/japanese/less \
		${X11BASE}/lib/X11/fonts/non-cjk/fonts.dir:${PORTSDIR}/x11/etlfonts
BUILD_DEPENDS=	mule:${PORTSDIR}/japanese/mule-wnn4

EXTRACT_ONLY=	dserver2.2betapl2.tar.gz dserver2.2betapl2.addtable.tar.gz
WRKSRC=		${WRKDIR}/dserver
USE_GMAKE=	yes

post-extract:
	@( \
	 cd  ${WRKSRC}/clients ; \
	 tar xzf diclookup-mule.tar.gz ; \
	 tar xzf ${DISTDIR}/diclookup-mule-2.3.0.add.tar.gz \
	)

pre-patch:
	@( \
	 cd  ${WRKSRC}/clients/diclookup-mule-2.3.0 ; \
	 ${PATCH} --quiet < od-ccl.oxford.patch \
	)

post-install:
	@${SED} s!PREFIX_DIR!${PREFIX}!g ${WRKSRC}/setup.sh.template \
	  > ${PREFIX}/lib/dserver/setup.sh
	@${SED} s!PREFIX_DIR!${PREFIX}!g ${WRKSRC}/deinstall.sh.template \
	  > ${PREFIX}/lib/dserver/deinstall.sh
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD-setup.euc ${PREFIX}/lib/dserver/doc/
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

.include <bsd.port.mk>
