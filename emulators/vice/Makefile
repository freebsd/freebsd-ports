# New ports collection makefile for:	vice
# Version required:	0.14.1
# Date created:		Mar 28, 1998
# Whom:			dchapes@ddm.on.ca
#
# $Id: Makefile,v 1.5 1998/07/19 19:32:02 dburr Exp $

DISTNAME=	vice-0.14.1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.funet.fi/pub/cbm/crossplatform/emulators/VICE/

MAINTAINER=	dchapes@ddm.on.ca

LIB_DEPENDS=	Xaw3d\\.6\\.:${PORTSDIR}/x11-toolkits/Xaw3d

WRKSRC=		${WRKDIR}/vice-0.14.1/src

RESTRICTED=	ROMs are copyrighted by Commodore Business Machines
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

GNU_CONFIGURE=	YES
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -O3 -Wall -fomit-frame-pointer -funroll-loops -finline-functions -fno-strength-reduce"
CONFIGURE_ARGS=	--with-xaw3d

MANPAGES=	vice c1541 petcat
MAN1=		vice.1 c1541.1 petcat.1

pre-build:
	@${ECHO} "NOTE:  When compiling on FreeBSD some source files cause gcc to go over the"
	@${ECHO} "default memory limits.  Either fix /etc/login.conf or temporaryily adjust"
	@${ECHO} "the limits with your shells limit command (\"unlimit\" works in [t]csh)."

pre-install:
	${SED} -e "s,%VER%,`uname -r | ${SED} -e 's,-.*$$,,'`," < ${PKGDIR}/PLIST.in > ${PKGDIR}/PLIST

post-install:
	for m in ${MANPAGES} ; do \
	  ${INSTALL_MAN} ${WRKSRC}/../man/$$m.man ${PREFIX}/man/man1/$$m.1; \
	done
.if defined(NOMANCOMPRESS)
	${LN} -sf vice.1 ${PREFIX}/man/man1/x64.1
	${LN} -sf vice.1 ${PREFIX}/man/man1/xvic.1
	${LN} -sf vice.1 ${PREFIX}/man/man1/xpet.1
	${LN} -sf vice.1 ${PREFIX}/man/man1/recomment.1
.else
	${LN} -sf vice.1.gz ${PREFIX}/man/man1/x64.1.gz
	${LN} -sf vice.1.gz ${PREFIX}/man/man1/xvic.1.gz
	${LN} -sf vice.1.gz ${PREFIX}/man/man1/xpet.1.gz
	${LN} -sf vice.1.gz ${PREFIX}/man/man1/recomment.1.gz
.endif

pre-clean:
	@${RM} -f ${PKGDIR}/PLIST

.include <bsd.port.mk>
