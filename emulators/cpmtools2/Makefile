# New ports collection makefile for:	cpmtools
# Date created:		31 January 2008
# Whom:			joerg
#
# $FreeBSD$
#

PORTNAME=	cpmtools
PORTVERSION=	2.8
CATEGORIES=	emulators sysutils
MASTER_SITES=	http://www.moria.de/~michael/cpmtools/ \
		http://www.copei.de/freebsd-ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools to access CP/M disks and disk images

LIB_DEPENDS+=	dmalloc:${PORTSDIR}/devel/dmalloc

BROKEN=		does not fetch

LATEST_LINK=	cpmtools2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--mandir=${PREFIX}/man --bindir=${PREFIX}/sbin \
		--datarootdir=${PREFIX}/share/${PORTNAME} --with-dmalloc

MAN1=	cpmls.1 cpmcp.1 cpmrm.1 cpmchmod.1 cpmchattr.1 mkfs.cpm.1 fsck.cpm.1 fsed.cpm.1
MAN5=	cpm.5

OPTIONS=	RAW_LIBDSK "With LIBDSK support with direct floppy access" on \
		LIBDSK "With LIBDSK support (no direct floppy access)" off

.include <bsd.port.pre.mk>

.if defined(WITH_LIBDSK) || defined(WITH_RAW_LIBDSK)
LIB_DEPENDS+=	dsk.5:${PORTSDIR}/emulators/libdsk
CONFIGURE_ARGS+=--with-libdsk=${LOCALBASE} --with-device=LibDsk
.else
CONFIGURE_ARGS+=--without-libdsk --with-device=posix
.endif

.if defined(WITH_RAW_LIBDSK)
CONFIGURE_ARGS+=--enable-floppy
.else
CONFIGURE_ARGS+=--disable-floppy
.endif

pre-install:
	@${MKDIR} ${DATADIR}

.include <bsd.port.post.mk>
