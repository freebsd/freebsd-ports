# New ports collection makefile for:	ja-tcl8.0
# Version required:	8.0
# Date created:		23 Jan 1998
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $Id: Makefile,v 1.2 1998/07/03 23:06:33 steve Exp $
#

DISTNAME=	tcl8.0p2
PKGNAME=	ja-tcl-8.0.2
CATEGORIES=	japanese lang tcl80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/lang/tcl/jp/
PATCHFILES=	tcl8.0p2jp1.0.patch.gz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

VERSION=	8.0
TOPDIR=		${WRKDIR}/tcl${VERSION}
WRKSRC=		${TOPDIR}/unix
.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=-d ${TOPDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=-d ${TOPDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif
GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--enable-shared

.if !defined(NOPORTDOCS)
post-patch:
	@${CP} ${FILESDIR}/README.FreeBSD.in ${TOPDIR}/README.FreeBSD.JP.in
	@${SED} -e 's%AC_OUTPUT(Makefile tclConfig.sh)%AC_OUTPUT(Makefile tclConfig.sh ../README.FreeBSD.JP)%' \
	  < ${WRKSRC}/configure.in \
	  > ${WRKSRC}/configure.in.tmp
	@${MV} -f ${WRKSRC}/configure.in.tmp ${WRKSRC}/configure.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tcl${VERSION}jp
	@(cd ${TOPDIR}; \
	  ${INSTALL_DATA} README changes README.FreeBSD.JP README.JP \
		changes.JP \
		Incompat80jp ${PREFIX}/share/doc/tcl${VERSION}jp; \
	 )
.endif
	@${LDCONFIG} -m ${PREFIX}/lib
	@${CAT}	${PKGDIR}/MESSAGE

test:
	cd ${WRKSRC} && ${MAKE} test

install-man:
	cd ${WRKSRC} && ${MAKE} install-man

.include <bsd.port.mk>
