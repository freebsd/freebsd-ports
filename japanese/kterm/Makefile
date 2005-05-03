# New ports collection makefile for:	kterm
# Date created:		18 November 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	kterm
PORTVERSION=	6.2.0
PORTREVISION=	6
CATEGORIES=	japanese x11
MASTER_SITES=	${MASTER_SITE_PORTS_JP:S/$/:wp_jp/} \
		${MASTER_SITE_XCONTRIB} \
		${MASTER_SITE_LOCAL:S/$/:wp_local/}
MASTER_SITE_SUBDIR=	applications kterm/:wp_jp shige/kterm/:wp_local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		README.wallpaper.ja:wp_local,wp_jp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xterm that speaks Japanese

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	kterm
PATCH_SITES=	ftp://ftp.sra.co.jp/pub/x11/kterm/:nfs \
		http://www.asahi-net.or.jp/~hc3j-tkg/kterm/:wpi \
		http://dists.lovepeers.org/distfiles/:termios \
		${MASTER_SITE_LOCAL:S/$/:jisx0213,color16,termios/}
PATCH_SITE_SUBDIR=	shige/kterm/:jisx0213,color16 \
       			nork/:termios
PATCHFILES=	${DISTNAME}.NFS-xauth.patch:nfs \
		${DISTNAME}-wpi.patch.gz:wpi \
		${DISTNAME}-jisx0213.patch.gz:jisx0213 \
		${DISTNAME}-color16.patch.gz:color16 \
		${DISTNAME}-termios-0.2.patch.gz:termios
PATCH_DIST_STRIP= -p1

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		kterm.1
MANCOMPRESSED=	yes

DOCDIR=		${PREFIX}/share/doc/kterm

.if !defined(PACKAGE_BUILDING)

.if defined(WITH_XAW3DLIB) && defined(WITH_NEXTAWLIB)
.BEGIN:
	@${ECHO} "Error: \$${WITH_XAW3DLIB} and \$${WITH_NEXTAWLIB} cannot be specified simultaneously!"
	@${FALSE}
.elif defined(WITH_XAW3DLIB)
LIB_DEPENDS+=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d
post-patch:
	@${ECHO_MSG}  "===>  Applying Xaw3d scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-Xaw3d
.elif defined(WITH_NEXTAWLIB)
LIB_DEPENDS+=	neXtaw:${PORTSDIR}/x11-toolkits/neXtaw
post-patch:
	@${ECHO_MSG}  "===>  Applying neXtaw scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-neXtaw
.endif
.if defined(WITH_TEKTRONIX)
post-patch:
	@${ECHO_MSG}  "===>  Applying Tektronix emulation patch"
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-Tektronix
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
