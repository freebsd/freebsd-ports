# New ports collection makefile for:	vMac
# Version required:		 	0.1.9.3
# Date created:				Jul 11th 1999
# Whom:					troll
#
# $FreeBSD$
#

DISTNAME=		vMac-0.1.9.3-src
PKGNAME=		vMac-0.1.9.3
CATEGORIES=		emulators
MASTER_SITES=		http://www.vmac.org/download/XWindows/
EXTRACT_SUFX=		.tgz

MAINTAINER=		troll@digitalspark.net

MAKEFILE=		Makefile
WRKSRC=			${WRKDIR}/vMac-0.1.9.3
USE_GMAKE=	 	yes
HAS_CONFIGURE=		yes
USE_XLIB=		yes

pre-patch:
	(cd ${WRKSRC} && sh ${FILESDIR}/dos2unx gemulator.c)

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vMac \
	    ${PREFIX}/bin
	@strip ${PREFIX}/bin/vMac
	@ ${MKDIR} ${PREFIX}/share/doc/vMac
	${INSTALL_DATA} ${WRKSRC}/CREDITS \
	    ${PREFIX}/share/doc/vMac
	${INSTALL_DATA} ${WRKSRC}/INSTALL \
	    ${PREFIX}/share/doc/vMac
	${INSTALL_DATA} ${WRKSRC}/LICENSE \
	    ${PREFIX}/share/doc/vMac
	${INSTALL_DATA} ${WRKSRC}/README \
	    ${PREFIX}/share/doc/vMac
	${INSTALL_DATA} ${WRKSRC}/README.rom \
	    ${PREFIX}/share/doc/vMac
	@${CAT} ${PKGDIR}/MESSAGE | ${SED} -e s:/usr/local:${PREFIX}:

.include <bsd.port.mk>
