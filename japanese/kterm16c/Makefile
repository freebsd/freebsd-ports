# New ports collection makefile for:	kterm
# Version required:	6.2
# Date created:		18 November 1994
# Whom:			asami
#
# $Id: Makefile,v 1.16 1997/12/25 22:29:38 asami Exp $
#

DISTNAME=	kterm-6.2.0
PKGNAME=	ja-kterm-6.2.0
CATEGORIES=	japanese x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/x11/kterm/ \
		http://karin.ip.titech.ac.jp/~takagi/kterm/
PATCHFILES=	kterm-6.2.0.NFS-xauth.patch \
		kterm-6.2.0-wpr1.patch.gz
PATCH_DIST_STRIP= -p1

USE_IMAKE=	yes
MAN1=		kterm.1
MANCOMPRESSED=	yes

DOCDIR=		${PREFIX}/share/doc/kterm

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

post-install:
# install japanese manual
	@${MV} ${WRKSRC}/kterm.jman ${WRKSRC}/kterm.jman.jis
	@nkf -e -u ${WRKSRC}/kterm.jman.jis >${WRKSRC}/kterm.jman
	@${INSTALL_MAN} ${WRKSRC}/kterm.jman ${PREFIX}/man/ja/man1/kterm.1
	@${GZIP_CMD} ${PREFIX}/man/ja/man1/kterm.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.kt ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.wallpaper ${DOCDIR}/README.wallpaper.ja
.endif

.include <bsd.port.mk>
