# New ports collection makefile for:	kterm
# Version required:	6.2
# Date created:		18 November 1994
# Whom:			asami
#
# $FreeBSD$
#

DISTNAME=	kterm-6.2.0
PKGNAME=	ja-kterm-6.2.0
CATEGORIES=	japanese x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		${MASTER_SITE_PORTS_JP} \
		http://www.freebsd.org/~shige/ports/kterm/
MASTER_SITE_SUBDIR=	applications kterm

MAINTAINER=	shige@FreeBSD.org

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

DISTFILES=	${DISTNAME}.tar.gz README.wallpaper.ja
EXTRACT_ONLY=	${DISTNAME}.tar.gz
PATCH_SITES=	ftp://ftp.sra.co.jp/pub/x11/kterm/ \
		http://www.asahi-net.or.jp/~hc3j-tkg/kterm/
PATCHFILES=	kterm-6.2.0.NFS-xauth.patch \
		kterm-6.2.0-wpi.patch.gz
DIST_SUBDIR=	kterm
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
	@${INSTALL_DATA} ${_DISTDIR}/README.wallpaper.ja ${DOCDIR}/README.wallpaper.ja
.endif

.include <bsd.port.mk>
