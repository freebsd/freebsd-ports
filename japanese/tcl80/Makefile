# New ports collection makefile for:	ja-tcl8.0
# Version required:	8.0
# Date created:		23 Jan 1998
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $Id: Makefile,v 1.7 1998/11/14 09:43:16 asami Exp $
#

DISTNAME=	tcl8.0.4
PKGNAME=	ja-tcl-8.0.4
CATEGORIES=	japanese lang tcl80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/lang/tcl/jp/
PATCHFILES=	tcl8.0.4jp1.3.patch.gz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

VERSION=	8.0
TOPDIR=		${WRKDIR}/${DISTNAME}
WRKSRC=		${TOPDIR}/unix
.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=-d ${TOPDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=-d ${TOPDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif
GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--enable-shared

.include <bsd.port.pre.mk>

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
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if ${PORTOBJFORMAT} == "aout" 
	${LN} -sf libtcl80jp.so.1.4 ${PREFIX}/lib/libtcl80jp.so
.endif
	@${CAT}	${PKGDIR}/MESSAGE

test:
	cd ${WRKSRC} && ${SETENV} PORTOBJFORMAT=${PORTOBJFORMAT} ${MAKE} test

install-man:
	cd ${WRKSRC} && ${SETENV} PORTOBJFORMAT=${PORTOBJFORMAT} ${MAKE} install-man

.include <bsd.port.post.mk>
