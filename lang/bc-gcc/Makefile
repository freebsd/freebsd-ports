# ex:ts=8
# Ports collection makefile for:  gcc-2.7.2 - Bounds checking gcc
# Version required:	gcc-2.7.2 + Bounds checking patches
# Date created:		Sun June 08, 1997
# Whom:			David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.2 1998/11/11 05:37:23 asami Exp $
#

DISTNAME=	gcc-2.7.2
PKGNAME=	bc-gcc-2.7.2p1.0.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}  \
		ftp://dse.doc.ic.ac.uk/pub/misc/bcc/  \
		ftp://ftp.cs.yale.edu/WWW/pub/bradley/bcc/  \
		ftp://ftp.cs.columbia.edu/archives/gnu/bcc/
MASTER_SITE_SUBDIR=	gcc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} documentation-as-8x11-ps.tgz

PATCH_SITES=	ftp://dse.doc.ic.ac.uk/pub/misc/bcc/  \
		ftp://ftp.cs.yale.edu/WWW/pub/bradley/bcc/  \
		ftp://ftp.cs.columbia.edu/archives/gnu/bcc/
PATCHFILES=	bounds-checking-2.7.2-1.02.tgz
PATCH_DIST_STRIP=	-p1 -N -E

MAINTAINER=	obrien@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300000
BROKEN=		"can't find /usr/lib/aout/crt0.o"
.endif

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${PATCHFILES}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gnu-as --with-gnu-ld
ALL_TARGET=	bootstrap LANGUAGES=c
INSTALL_TARGET=	install LANGUAGES=c
GNUHOST=	i386-unknown-freebsd${OSREL}
PLIST_SUB=	GNUHOST=${GNUHOST}
MAN1=		bc-gcc.1 bc-cccp.1

pre-patch:
	cd ${WRKSRC} ; ${PATCH} -p1 < bounds-checking.diff

pre-configure:
	@( cd ${WRKSRC}/config/i386/ ; \
	MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${MV} freebsd.h freebsd.h.in ; \
	${SED} -e "s:__FreeBSD__=[0-9]*:__FreeBSD__=$${MAJ}:" freebsd.h.in \
		>freebsd.h )
	cd ${WRKSRC} ; ./configure ; make distclean

post-install:
	@mv ${PREFIX}/bin/gcc ${PREFIX}/bin/bc-gcc
	@mv ${PREFIX}/bin/${GNUHOST}-gcc ${PREFIX}/bin/${GNUHOST}-bc-gcc
	@mv ${PREFIX}/man/man1/gcc.1 ${PREFIX}/man/man1/bc-gcc.1
	@mv ${PREFIX}/man/man1/cccp.1 ${PREFIX}/man/man1/bc-cccp.1
	@( for prog in ${PREFIX}/bin/bc-gcc ${PREFIX}/bin/${GNUHOST}-bc-gcc ; \
		do strip $$prog ; \
		done )

.include <bsd.port.post.mk>
