# Created by: sada
# $FreeBSD$

PORTNAME=	mikachan-ttfonts
PORTVERSION=	9.1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://mikachan.sourceforge.jp/
DISTNAME=	ver${PORTVERSION}
EXTRACT_SUFX=	.lzh

MAINTAINER=	turutani@scphys.kyoto-u.ac.jp
COMMENT=	Handwritten Japanese TrueType fonts by Mika-chan

EXTRACT_DEPENDS=	lha:${PORTSDIR}/archivers/lha

NO_CDROM=	Don't sell distfile
EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	pq
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/mika.ttf
DIST_SUBDIR=	${PORTNAME}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

FONTSDIR=	lib/X11/fonts/TrueType

NO_STAGE=	yes
do-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${INSTALL_DATA} \
		${WRKDIR}/mika.ttf ${FILESDIR}/fonts.dir.mika \
		${PREFIX}/${FONTSDIR}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
