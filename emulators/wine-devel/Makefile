# New ports collection makefile for:    wine
# Version required:     980517
# Date created:         Sa   9 Nov 1996 00:52:22 MET
# Whom:			se
#
# $FreeBSD$
#

DATE=		991031
DISTNAME=	Wine-${DATE}
PKGNAME=	wine-99.10.31
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/wine/development

MAINTAINER=	se@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wine-${DATE}
GNU_CONFIGURE=	yes
MAN1=		wine.1
MAN1=		wine.conf.5
ONLY_FOR_ARCHS=	i386

STRIP=
CFLAGS+=	-g

post-configure:
		cd ${WRKSRC} && make depend

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wine ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/fnt2bdf ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/windows/x11drv/wineclipsrv ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.sample
	[ -f ${PREFIX}/etc/wine.conf ] \
		|| ${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf
	${INSTALL_DATA} ${WRKSRC}/wine.sym ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/documentation/wine.man ${PREFIX}/man/man1/wine.1
	${INSTALL_DATA} ${WRKSRC}/documentation/wine.conf.man ${PREFIX}/man/man5/wine.conf.5
	-@${MKDIR} ${PREFIX}/lib/wine 2>/dev/null
	${INSTALL_DATA} ${FILESDIR}/README.patch \
		${FILESDIR}/patch-3.3-sys-ldtshare \
		${FILESDIR}/patch-3.3-sys-sigtrap \
		${PREFIX}/lib/wine
	${INSTALL_DATA} ${WRKSRC}/winedefault.reg ${PREFIX}/lib/wine/
	${ECHO}
	@${SED} s+%%PREFIX%%+${PREFIX}+g <${PKGMESSAGE}

.include <bsd.port.mk>
