# New ports collection makefile for:	ja-tk8.0
# Version required:	8.0
# Date created:		26 Dec 1997
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $Id: Makefile,v 1.9 1998/11/14 09:43:17 asami Exp $
#

DISTNAME=	tk8.0.4
PKGNAME=	ja-tk-8.0.4
CATEGORIES=	japanese x11-toolkits tk80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/lang/tcl/jp/
PATCHFILES=	tk8.0.4jp1.3.patch.gz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	tcl80jp.1:${PORTSDIR}/japanese/tcl80

VERSION=	8.0
TOPDIR=		${WRKDIR}/${DISTNAME}
WRKSRC=		${TOPDIR}/unix
.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=-d ${TOPDIR} -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=-d ${TOPDIR} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif
USE_AUTOCONF=	yes
USE_XLIB=	yes
CONFIGURE_ARGS=	--enable-shared --with-tcl=${PREFIX}/lib/tcl${VERSION}jp

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
post-patch:
	@${CP} ${FILESDIR}/README.FreeBSD.in ${TOPDIR}/README.FreeBSD.JP.in
	@${SED} -e 's%AC_OUTPUT(Makefile tkConfig.sh)%AC_OUTPUT(Makefile tkConfig.sh ../README.FreeBSD.JP)%' \
	  < ${WRKSRC}/configure.in \
	  > ${WRKSRC}/configure.in.tmp
	@${MV} -f ${WRKSRC}/configure.in.tmp ${WRKSRC}/configure.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tk${VERSION}jp
	@(cd ${TOPDIR}; \
	  ${INSTALL_DATA} README changes README.FreeBSD.JP \
		README.JP changes.JP \
		Incompat80jp ${PREFIX}/share/doc/tk${VERSION}jp; \
	 )
.endif
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libtk80jp.so.1.4 ${PREFIX}/lib/libtk80jp.so
.endif
	@${CAT}	${PKGDIR}/MESSAGE

test:
	cd ${WRKSRC} && ${MAKE} test

install-man:
	cd ${WRKSRC} && ${MAKE} install-man

.include <bsd.port.post.mk>
