# Created by: joerg
# $FreeBSD$

PORTNAME=	cpmtools
PORTVERSION=	2.16
CATEGORIES=	emulators sysutils
MASTER_SITES=	http://www.moria.de/~michael/cpmtools/

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Tools to access CP/M disks and disk images

LICENSE=	GPLv3

LATEST_LINK=	cpmtools2

NO_STAGE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--bindir=${PREFIX}/sbin \
		--datarootdir=${DATADIR}

MAN1=	cpmls.1 cpmcp.1 cpmrm.1 cpmchmod.1 cpmchattr.1 mkfs.cpm.1 fsck.cpm.1 fsed.cpm.1
MAN5=	cpm.5

OPTIONS_DEFINE=	LIBDSK

LIBDSK_DESC=	Access to disks and disk images support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBDSK}
LIB_DEPENDS+=	dsk:${PORTSDIR}/emulators/libdsk
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

.include <bsd.port.mk>
