# New ports collection makefile for:    ja-wine
# Date created:         14 Jan 1998
# Whom:			Takashi Uozu <j1594016@ed.kagu.sut.ac.jp>
#
# $FreeBSD$

PORTNAME=	wine
PORTVERSION=	99.01.31
CATEGORIES=	japanese emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www1.mahoroba.ne.jp/~jkuchi/wine-jp/src/
MASTER_SITE_SUBDIR=	ALPHA/wine/development
DISTNAME=	ja-Wine-${PORTVERSION:S/.//g}
DISTFILES=	Wine-${PORTVERSION:S/.//g}.tar.gz \
		Wine${PORTVERSION:S/.//g}-ja.tar.gz

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}
PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-japanese --with-kinput

MAN1=		wine.1

pre-patch:
	@(cd ${WRKDIR}; \
	  ${PATCH} ${PATCH_ARGS} < ${WRKDIR}/Wine${PORTVERSION:S/.//g}-jp.Patch)

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
