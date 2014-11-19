# Created by: joerg
# $FreeBSD$

PORTNAME=	cpmtools2
PORTVERSION=	2.20
CATEGORIES=	emulators sysutils
MASTER_SITES=	http://www.moria.de/~michael/cpmtools/files/
DISTNAME=	${PORTNAME:C/2$//}-${PORTVERSION}

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Tools to access CP/M disks and disk images

LICENSE=	GPLv3

USES=	desthack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--bindir=${STAGEDIR}${PREFIX}/sbin \
		--datarootdir=${DATADIR}

OPTIONS_DEFINE=	LIBDSK

LIBDSK_DESC=	Access to disks and disk images support

LIBDSK_CONFIGURE_ON=	--with-libdsk=${LOCALBASE}
LIBDSK_CONFIGURE_OFF=	--with-libdsk=''
LIBDSK_LIB_DEPENDS=	libdsk.so:${PORTSDIR}/emulators/libdsk

# remove unneeded getopt*.c
# remove curses from all but fsed.cpm
# fixes for stage
post-patch:
	@${REINPLACE_CMD} -e 's|getopt$$(OBJEXT)||g; s|getopt1$$(OBJEXT)||g' \
		-e 's|\($$(CC).*fsed.cpm$$(OBJEXT).*$$(DEVICEOBJ)\)|\1 -lcurses|' \
		-e '/^CFLAGS=/s|@CFLAGS@|@CFLAGS@ -DDISKDEFS=\\"@datarootdir@/diskdefs\\" -DFORMAT=\\"$$(DEFFORMAT)\\"|' \
		-e 's|diskdefs @datarootdir@/diskdefs|diskdefs $$(DESTDIR)@datarootdir@/diskdefs|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\(FSED_CPM=fsed.cpm\) LIBS=\"-lcurses $$LIBS\"|\1|' \
		${WRKSRC}/configure

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
