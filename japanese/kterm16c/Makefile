# New ports collection makefile for:	kterm of 16 colors
# Version required:	6.2
# Date created:		18 November 1994
# Whom:			asami
#
# $Id: Makefile,v 1.17 1998/12/23 01:47:23 steve Exp $
#

DISTNAME=	kterm-6.2.0
PKGNAME=	ja-kterm16c-6.2.0
CATEGORIES=	japanese x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		ftp://ftp.interface-business.de/pub/outgoing/ \
		ftp://ftp.cs.bris.ac.uk/pub/users/hedley/
DISTFILES=	kterm-6.2.0.tar.gz pcemu1.01alpha.tar.gz
EXTRACT_ONLY=	kterm-6.2.0.tar.gz

MASTER_SITE_SUBDIR=	applications

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/x11/kterm/ \
		http://karin.ip.titech.ac.jp/~takagi/kterm/
PATCHFILES=	kterm-6.2.0.NFS-xauth.patch \
		kterm-6.2.0-wpr1.patch.gz
PATCH_DIST_STRIP= -p1

USE_IMAKE=	yes

DOCDIR=		${PREFIX}/share/doc/kterm16c

post-extract:
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/pcemu1.01alpha.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${WRKDIR} pcemu1.01alpha/vga.bdf
	@cd ${WRKDIR}/pcemu1.01alpha; \
		bdftopcf vga.bdf > vga.pcf; \
		${GZIP_CMD} vga.pcf

.if !defined(PACKAGE_BUILDING)

.if defined(USE_XAW3DLIB) && defined(USE_NEXTAWLIB)
.if (${USE_XAW3DLIB} == "YES") && (${USE_NEXTAWLIB} == "YES")
.BEGIN:
	@${ECHO} "Error: \$${USE_XAW3DLIB} and \$${USE_NEXTAWLIB} cannot be specified simultaneously!"
	@${FALSE}
.endif
.elif defined(USE_XAW3DLIB)
.if (${USE_XAW3DLIB} == "YES")
LIB_DEPENDS+=	Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d
post-patch:
	@${ECHO_MSG}  "===>  Applying Xaw3d scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-Xaw3d
.endif
.elif defined(USE_NEXTAWLIB)
.if (${USE_NEXTAWLIB} == "YES")
LIB_DEPENDS+=	neXtaw.6:${PORTSDIR}/x11-toolkits/neXtaw
post-patch:
	@${ECHO_MSG}  "===>  Applying neXtaw scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-neXtaw
.endif
.endif
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/kterm ${PREFIX}/bin/kterm16c
	@${INSTALL_DATA} ${WRKSRC}/KTerm.ad ${PREFIX}/lib/X11/app-defaults/KTerm.16-colors
	@${INSTALL_DATA} ${WRKDIR}/pcemu1.01alpha/vga.pcf.gz \
		${PREFIX}/lib/X11/fonts/misc
	@mkfontdir ${PREFIX}/lib/X11/fonts/misc

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${FILESDIR}/dot.termcap ${DOCDIR}
	@${INSTALL_DATA} ${FILESDIR}/kterm16c.doc ${DOCDIR}
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
