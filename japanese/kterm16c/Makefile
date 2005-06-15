# New ports collection makefile for:	kterm of 16 colors
# Date created:		18 November 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	kterm16c
PORTVERSION=	6.2.0
CATEGORIES=	japanese x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		ftp://ftp.interface-business.de/pub/outgoing/ \
		ftp://ftp.cs.bris.ac.uk/pub/users/hedley/
MASTER_SITE_SUBDIR=	applications
DISTNAME=	kterm-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pcemu1.01alpha.tar.gz
DIST_SUBDIR=	kterm
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/x11/kterm/ \
		http://www.asahi-net.or.jp/~hc3j-tkg/kterm/
PATCHFILES=	${DISTNAME}.NFS-xauth.patch \
		${DISTNAME}-wpr1.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xterm that speaks Japanese with 16 colors like on a VGA

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf \
		mkfontdir:${X_CLIENTS_PORT}
EXTRACT_DEPENDS=bdftopcf:${X_CLIENTS_PORT}

USE_IMAKE=	yes
USE_XPM=	yes

.include <bsd.port.pre.mk>

DOCDIR=		${PREFIX}/share/doc/kterm16c

post-extract:
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/pcemu1.01alpha.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${WRKDIR} pcemu1.01alpha/vga.bdf
	@cd ${WRKDIR}/pcemu1.01alpha; \
		bdftopcf vga.bdf > vga.pcf; \
		${GZIP_CMD} vga.pcf

.if !defined(PACKAGE_BUILDING)

.if defined(WITH_XAW3DLIB) && defined(WITH_NEXTAWLIB)
.BEGIN:
	@${ECHO} "Error: \$${WITH_XAW3DLIB} and \$${WITH_NEXTAWLIB} cannot be specified simultaneously!"
	@${FALSE}
.elif defined(WITH_XAW3DLIB)
LIB_DEPENDS+=	Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d
post-patch:
	@${ECHO_MSG}  "===>  Applying Xaw3d scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-Xaw3d
.elif defined(WITH_NEXTAWLIB)
LIB_DEPENDS+=	neXtaw.6:${PORTSDIR}/x11-toolkits/neXtaw
post-patch:
	@${ECHO_MSG}  "===>  Applying neXtaw scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-neXtaw
.endif

.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/kterm ${PREFIX}/bin/kterm16c
	@${INSTALL_DATA} ${WRKSRC}/KTerm.ad ${PREFIX}/lib/X11/app-defaults/KTerm
	@${MKDIR} ${PREFIX}/lib/X11/fonts/misc
	@${INSTALL_DATA} ${WRKDIR}/pcemu1.01alpha/vga.pcf.gz \
		${PREFIX}/lib/X11/fonts/misc
	@mkfontdir ${PREFIX}/lib/X11/fonts/misc

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${FILESDIR}/dot.termcap ${DOCDIR}
	@${INSTALL_DATA} ${FILESDIR}/kterm16c.doc ${DOCDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
