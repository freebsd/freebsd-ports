# New ports collection makefile for:   xgs-0.40
# Version required:	0.40
# Date created:		17th January 1996
# Whom:			Joel Sutton <suttonj@interconnect.com.au>
#
# $Id$
#
      
DISTNAME=	xgs-0.40
CATEGORIES=	emulators
MASTER_SITES=	http://www.optera.com/~invid/emulators/XGS/ \
		ftp://ftp.apple.asimov.net/pub/apple_II/emulators/rom_images/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ROMFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	suttonj@interconnect.com.au

NO_PACKAGE=	${RESTRICTED}
RESTRICTED=	xgs.rom copyright is owned by Apple and cannot be distributed
WRKSRC=		${WRKDIR}/xgs
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-oss-sound --prefix=${PREFIX}

#INSTALL_DATA?=	install -c -o bin -g bin
ROMFILE=	xgs.rom
XGS=		/share/xgs
      
post-patch:
	cp ${DISTDIR}/${ROMFILE} ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} -m 644 ${WRKSRC}/CHANGES ${WRKSRC}/COMPATIBILITY \
		${WRKSRC}/README ${WRKSRC}/TO-DO ${PREFIX}${XGS}/
	${INSTALL_DATA} -m 644 ${PKGDIR}/DESCR ${PREFIX}${XGS}/README.FreeBSD
.endif
	${INSTALL_DATA} -m 666 /dev/null ${PREFIX}${XGS}/xgs.ram

.include <bsd.port.mk>
