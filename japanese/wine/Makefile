# New ports collection makefile for:	ja-wine
# Version required:	971130
# Date created:		14 Jan 1998
# Whom:			Takashi Uozu <j1594016@ed.kagu.sut.ac.jp>
#
# $Id: Makefile,v 1.4 1998/09/17 00:32:43 asami Exp $

DISTNAME=	ja-Wine-971130
PKGNAME=	ja-wine-97.11.30
CATEGORIES=	japanese emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://karin.ip.titech.ac.jp/~takagi/wine/patch/
MASTER_SITE_SUBDIR=	ALPHA/wine/development
DISTFILES=	Wine-971130.tar.gz Wine971130-jp.tar.gz

MAINTAINER=	j1594016@ed.kagu.sut.ac.jp

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

BROKEN=		fetch

WRKSRC=		${WRKDIR}/wine971130
PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-japanese --with-kinput

MAN1=		wine.1

pre-patch:
	@(cd ${WRKDIR}; \
	  ${PATCH} ${PATCH_ARGS} < ${WRKDIR}/Wine971130-jp.Patch)

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

.include <bsd.port.mk>
