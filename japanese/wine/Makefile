# New ports collection makefile for:    ja-wine
# Version required:     971130
# Date created:         14 Jan 1998
# Whom:			Takashi Uozu <j1594016@ed.kagu.sut.ac.jp>
#
# $Id: Makefile,v 1.5 1999/02/20 07:14:26 asami Exp $

DISTNAME=	ja-Wine-990131
PKGNAME=	ja-wine-99.01.31
CATEGORIES=	japanese emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www1.mahoroba.ne.jp/~jkuchi/wine-jp/src/
MASTER_SITE_SUBDIR=	ALPHA/wine/development
DISTFILES=	Wine-990131.tar.gz Wine990131-ja.tar.gz

MAINTAINER=	j1594016@ed.kagu.sut.ac.jp

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wine-990131
PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-japanese --with-kinput

MAN1=		wine.1

pre-patch:
	@(cd ${WRKDIR}; \
	  ${PATCH} ${PATCH_ARGS} < ${WRKDIR}/Wine990131-jp.Patch)

pre-configure:
	@${ECHO} "WINE_INI_GLOBAL \"${PREFIX}/etc/wine.conf\"" \
	  >> ${WRKSRC}/autoconf.h

post-configure:
	cd ${WRKSRC} && make depend

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wine ${PREFIX}/bin
	-@${MKDIR} ${PREFIX}/etc 2>/dev/null
	[ -f ${PREFIX}/etc/wine.conf ] \
	  || ${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf
	${INSTALL_DATA} ${WRKSRC}/wine.sym ${PREFIX}/etc
	${INSTALL_DATA} \
	  ${WRKSRC}/documentation/wine.man ${PREFIX}/man/man1/wine.1

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/ja/wine
	${INSTALL_MAN} ${WRKDIR}/README.jis ${PREFIX}/share/doc/ja/wine
.endif

.include <bsd.port.mk>
