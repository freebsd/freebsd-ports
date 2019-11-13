# Created by: nox@FreeBSD.org
# $FreeBSD$

COMMENT=	QEMU CPU Emulator github bsd-user branch - static user targets
PKGNAMESUFFIX=	-user-static

QEMU_USER_STATIC=	yes
PKGMESSAGE=	/dev/null
DESCR=		${.CURDIR}/pkg-descr
OPTIONS_SLAVE=	STATIC_LINK BSD_USER X86_TARGETS
OPTIONS_EXCLUDE=SAMBA X11 GTK2 OPENGL GNUTLS SASL JPEG PNG CURL \
		CDROM_DMA PCAP USBREDIR GNS3 DOCS
MASTERDIR=	${.CURDIR}/../qemu-sbruno
CONFIGURE_ARGS+=	--extra-cflags=-D_IFI_OQDROPS

NOT_FOR_ARCHS=		powerpc64
NOT_FOR_ARCHS_REASON=	error: Unhandled abi

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/bin/qemu-ga
	@${RM} -r ${STAGEDIR}${PREFIX}/bin/qemu-img
	@${RM} -r ${STAGEDIR}${PREFIX}/bin/qemu-io
	@${RM} -r ${STAGEDIR}${PREFIX}/bin/qemu-nbd
	@${RM} -r ${STAGEDIR}${PREFIX}/bin/ivshmem-client
	@${RM} -r ${STAGEDIR}${PREFIX}/bin/ivshmem-server
	@${MV} ${STAGEDIR}${PREFIX}/etc/rc.d ${WRKDIR}
	@${RM} -r ${STAGEDIR}${PREFIX}/etc
.if exists(/usr/sbin/binmiscctl)
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	@${MV} ${WRKDIR}/rc.d ${STAGEDIR}${PREFIX}/etc
.endif
	@${RM} -r ${STAGEDIR}${PREFIX}/man
	@${RM} -r ${STAGEDIR}${DATADIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*
	@(cd ${STAGEDIR}${PREFIX}/bin && \
		for i in qemu-*; do ${MV} -i $$i $$i-static; done)

.include "${MASTERDIR}/Makefile"
