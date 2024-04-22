PORTNAME=	cpmtools2
PORTVERSION=	2.24
PORTREVISION=	1
CATEGORIES=	emulators sysutils
MASTER_SITES=	http://www.moria.de/~michael/cpmtools/files/
DISTNAME=	${PORTNAME:C/2$//}-${PORTVERSION}

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Tools to access CP/M disks and disk images
WWW=		http://www.moria.de/~michael/cpmtools/

LICENSE=	GPLv3

USES=		ncurses
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=	--bindir=${PREFIX}/sbin \
		--datarootdir=${DATADIR}

OPTIONS_DEFINE=	LIBDSK

LIBDSK_DESC=	Access to disks and disk images support

LIBDSK_CONFIGURE_ON=	--with-libdsk=${LOCALBASE}
LIBDSK_CONFIGURE_OFF=	--with-libdsk=''
LIBDSK_LIB_DEPENDS=	libdsk.so:emulators/libdsk

# remove unneeded getopt*.c
# remove curses from all but fsed.cpm
# fixes for stage
post-patch:
	@${REINPLACE_CMD} -e 's|getopt$$(OBJEXT)||g; s|getopt1$$(OBJEXT)||g' \
		-e 's|\($$(CC).*fsed.cpm$$(OBJEXT).*$$(DEVICEOBJ)\)|\1 -lncurses|' \
		-e '/^CFLAGS=/s|@CFLAGS@|@CFLAGS@ -DDISKDEFS=\\"@datarootdir@/diskdefs\\" -DFORMAT=\\"$$(DEFFORMAT)\\"|' \
		-e 's|diskdefs @datarootdir@/diskdefs|diskdefs $$(DESTDIR)@datarootdir@/diskdefs|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\(FSED_CPM=fsed.cpm\) LIBS=\"-lcurses $$LIBS\"|\1|' \
		${WRKSRC}/configure

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
