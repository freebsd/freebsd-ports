# New ports collection makefile for:	vMac
# Date created:				Jul 11th 1999
# Whom:					troll
#
# $FreeBSD$
#

PORTNAME=		vMac
PORTVERSION=		0.1.9.3
PORTREVISION=	1
CATEGORIES=		emulators
MASTER_SITES=		http://www.vmac.org/download/XWindows/
DISTNAME=		${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=		.tgz

MAINTAINER=		troll@digitalspark.net
COMMENT=	Emulates a MacPlus machine!  Runs MacOS versions up to 7.5.5

MAKEFILE=		Makefile
WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	 	yes
HAS_CONFIGURE=		yes
USE_XLIB=		yes

pre-patch:
	(cd ${WRKSRC} && sh ${FILESDIR}/dos2unx gemulator.c)

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vMac \
	    ${PREFIX}/bin
	@${STRIP_CMD} ${PREFIX}/bin/vMac
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
	@${CAT} ${PKGMESSAGE} | ${SED} -e s:/usr/local:${PREFIX}:

.include <bsd.port.mk>
