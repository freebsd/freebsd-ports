# New ports collection makefile for:	vice
# Version required:	0.14.1
# Date created:		Mar 28, 1998
# Whom:			dchapes@ddm.on.ca
#
# $Id$

DISTNAME=	vice-0.14.1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.funet.fi/pub/cbm/crossplatform/emulators/VICE/

MAINTAINER=	dchapes@ddm.on.ca

WRKSRC=		${WRKDIR}/vice-0.14.1/src

RESTRICTED=	ROMs are copyrighted by Commodore Business Machines

GNU_CONFIGURE=	YES
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -O3 -Wall -fomit-frame-pointer -funroll-loops -finline-functions -fno-strength-reduce"
CONFIGURE_ARGS=	--with-xaw3d

MANPAGES=	vice c1541 petcat
MAN1=		vice.1 c1541.1 petcat.1

pre-build:
	${ECHO} ${OSVER}

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
