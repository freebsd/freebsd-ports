# New ports collection makefile for:	kterm
# Date created:		18 November 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	kterm
PORTVERSION=	6.2.0
PORTREVISION=	5
CATEGORIES=	japanese x11
MASTER_SITES=	${MASTER_SITE_PORTS_JP} \
		${MASTER_SITE_XCONTRIB} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	applications kterm shige/kterm
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		README.wallpaper.ja

MAINTAINER=	shige@FreeBSD.org

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	kterm
PATCH_SITES=	ftp://ftp.sra.co.jp/pub/x11/kterm/ \
		http://www.asahi-net.or.jp/~hc3j-tkg/kterm/ \
		${MASTER_SITE_PORTS_JP} \
		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	shige/kterm
PATCHFILES=	${DISTNAME}.NFS-xauth.patch \
		${DISTNAME}-wpi.patch.gz \
		${DISTNAME}-jisx0213.patch.gz \
		${DISTNAME}-color16.patch.gz
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
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
post-patch:
	@${ECHO_MSG}  "===>  Applying Xaw3d scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-Xaw3d
.elif defined(WITH_NEXTAWLIB)
LIB_DEPENDS+=	neXtaw.${XAWVER}:${PORTSDIR}/x11-toolkits/neXtaw
post-patch:
	@${ECHO_MSG}  "===>  Applying neXtaw scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-neXtaw
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
