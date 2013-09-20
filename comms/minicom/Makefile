# Created by: obrien@cs.ucdavis.edu
# $FreeBSD$

PORTNAME=	minicom
PORTVERSION=	2.6.2
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	https://alioth.debian.org/frs/download.php/file/3869/ \
		http://alioth.debian.org/frs/download.php/file/3869/ \
		http://fossies.org/linux/misc/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	An MS-DOS Telix serial communication program "workalike"

OPTIONS_DEFINE=	DOCS NLS LRZSZ
OPTIONS_DEFAULT=LRZSZ
LRZSZ_DESC=	Install X/Y/ZMODEM protocol handlers

USES=		iconv
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-dfl-baud=57600 \
			--sysconfdir=${PREFIX}/etc/minicom \
			--enable-lock-dir=/var/spool/lock \
			--enable-dfl-port=/dev/cuau0
MAKE_ARGS+=	LIBS+="${ICONV_LIB} -lcurses"

MAN1=		minicom.1 runscript.1 ascii-xfr.1 xminicom.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLRZSZ}
RUN_DEPENDS+=	lrz:${PORTSDIR}/comms/lrzsz
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s@/usr/local/bin/@${LOCALBASE}/bin/@; \
		s@/sz@/lsz@;s@/sb@/lsb@;s@/sx@/lsx@;s@/rz@/lrz@; \
		s@/rb@/lrb@;s@/rx@/lrx@" ${WRKSRC}/src/rwconf.c
	${REINPLACE_CMD} -E -e "s@^(SUBDIRS = .*) intl@\1@" \
		${WRKSRC}/Makefile.in

post-install:
	${CHOWN} uucp:dialer ${PREFIX}/bin/minicom
	${CHMOD} 4511 ${PREFIX}/bin/minicom
	${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/etc/minicom
	${CHOWN} uucp ${PREFIX}/etc/minicom
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}/
	(umask 022 && cd ${WRKSRC} && ${TAR} --exclude '*/Makefile*' \
		 --exclude '*.orig' -chf - extras doc | ${TAR}  -xf - -C \
		${DOCSDIR})
.endif

.include <bsd.port.post.mk>
