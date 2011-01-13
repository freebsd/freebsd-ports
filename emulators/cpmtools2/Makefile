# New ports collection makefile for:	cpmtools
# Date created:		31 January 2008
# Whom:			joerg
#
# $FreeBSD$
#

PORTNAME=	cpmtools
PORTVERSION=	2.13
CATEGORIES=	emulators sysutils
MASTER_SITES=	http://www.moria.de/~michael/cpmtools/

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	Tools to access CP/M disks and disk images

LATEST_LINK=	cpmtools2

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--bindir=${PREFIX}/sbin \
		--datarootdir=${DATADIR}

MAN1=	cpmls.1 cpmcp.1 cpmrm.1 cpmchmod.1 cpmchattr.1 mkfs.cpm.1 fsck.cpm.1 fsed.cpm.1
MAN5=	cpm.5

OPTIONS=	LIBDSK "With LIBDSK support" off

.include <bsd.port.pre.mk>

.if defined(WITH_LIBDSK)
LIB_DEPENDS+=	dsk.5:${PORTSDIR}/emulators/libdsk
CONFIGURE_ARGS+=--with-libdsk=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-libdsk=''
.endif

# remove unneeded getopt*.c
# remove curses from all but fsed.cpm
post-patch:
	@${REINPLACE_CMD} -e 's|getopt$$(OBJEXT)||g; s|getopt1$$(OBJEXT)||g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\($$(CC).*fsed.cpm$$(OBJEXT).*$$(DEVICEOBJ)\)|\1 -lcurses|' \
		${WRKSRC}/Makefile.in

pre-install:
	@${MKDIR} ${DATADIR}

.include <bsd.port.post.mk>
