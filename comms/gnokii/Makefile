# Created by: Staffan Ulfberg <staffanu@multivac.fatburen.org>
# $FreeBSD$

PORTNAME=	gnokii
PORTVERSION=	0.6.31
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.gnokii.org/download/gnokii/ \
		ftp://ftp.gnokii.org/pub/gnokii/ \
		http://www.gnokii.org/download/gnokii/0.6.x/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Tools to talk to GSM cellular phones

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

GROUPS=		${PORTNAME}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_CSTD=	gnu89
MAKE_JOBS_SAFE=	yes
WANT_GNOME=	yes
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
CPPFLAGS+=	${CFLAGS} -I${LOCALBASE}/include -fPIC
CONFIGURE_ARGS+=	--enable-security
CONFIGURE_ENV+=	MSGFMT="${LOCALBASE}/bin/msgfmt" \
		XGETTEXT="${LOCALBASE}/bin/xgettext" \
		LIBS="-L${WRKSRC}/common -L${LOCALBASE}/lib" \
		PKG_CONFIG="${LOCALBASE}/bin/pkg-config"
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES+=	pkg-message
PORTDOCS=	*
MAN1=		gnokii.1 sendsms.1 xgnokii.1
MAN8=		gnokiid.8 mgnokiidev.8

CONFLICTS=	smstools-[0-9]* sendsms-[0-9]*

OPTIONS_DEFINE=	DOCS ICAL PCSC SMSD SMSDDB USB X11
OPTIONS_MULTI=	SMSDDB
OPTIONS_MULTI_SMSDDB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	X11

ICAL_DESC=	Build with IETF iCal support
USB_DESC=	Build with libusb support
PCSC_DESC=	Build with PC/SC-Lite support
SMSD_DESC=	Enable smsd daemon (includes "file" backend)
SMSDDB_DESC=	Enable database support in smsd (select one or more)
X11_DESC=	Build graphical version (xgnokii)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICAL}
LIB_DEPENDS+=		ical:${PORTSDIR}/devel/libical
.else
CONFIGURE_ARGS+=	--disable-libical
.endif

.if ${OSVERSION} < 800069
. if ${PORT_OPTIONS:MUSB}
LIB_DEPENDS+=		usb-0.1.8:${PORTSDIR}/devel/libusb
. else
CONFIGURE_ARGS+=	--disable-libusb
. endif
.endif

.if ${PORT_OPTIONS:MPCSC}
LIB_DEPENDS+=		pcsclite:${PORTSDIR}/devel/pcsc-lite
.else
CONFIGURE_ARGS+=	--disable-libpcsclite
.endif

.if empty(PORT_OPTIONS:MSMSD)
PLIST_SUB+=	SMSD='@comment ' MSM='@comment ' PGM='@comment ' SQLT='@comment '
CONFIGURE_ARGS+=	--disable-smsd
.else
PLIST_SUB+=	SMSD=''
USE_GNOME+=	glib20
MAN8+=		smsd.8
. if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
PLIST_SUB+=	MSM=''
. else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=	MSM='@comment '
. endif
. if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
PLIST_SUB+=	PGM=''
. else
CONFIGURE_ARGS+=	--disable-postgres
PLIST_SUB+=	PGM='@comment '
. endif
. if ${PORT_OPTIONS:MSQLITE}
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
PLIST_SUB+=	SQLT=''
. else
CONFIGURE_ARGS+=	--disable-sqlite
PLIST_SUB+=	SQLT='@comment '
. endif
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--with-x
USE_XORG=	xpm
USE_GNOME+=	gtk20
PLIST_SUB+=	X11=''
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11='@comment '
.endif

FIXPREFIX=	Docs/man/gnokiid.8 Docs/DataCalls-QuickStart Docs/README \
		common/cfgreader.c
post-patch:
.for f in ${FIXPREFIX}
	@${REINPLACE_CMD} -e "s:/etc/gnokiirc:${PREFIX}/etc/gnokiirc:g" \
		${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e "s:%%PTHREAD_LIBS%%:${PTHREAD_LIBS}:; \
		s:%%PTHREAD_CFLAGS%%:${PTHREAD_CFLAGS}:" ${WRKSRC}/configure
.for f in common/data/virtmodem.c utils/mgnokiidev.c
	@${REINPLACE_CMD} -E -e "s:^(#ifdef.*)__OpenBSD__:\1__FreeBSD__:" \
		${WRKSRC}/${f}
.endfor
# fix test(1) conditions in configure script
	@${REINPLACE_CMD} -E \
		-e 's|([[:space:]]+test[[:space:]]+.+)==([[:space:]]+"yes")|\1=\2|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${MV} ${WRKSRC}/Docs/man/xgnokii.1x ${WRKSRC}/Docs/man/xgnokii.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/xgnokii/xgnokii.pc ${PREFIX}/libdata/pkgconfig
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if ${PORT_OPTIONS:MDOCS}
	${GMAKE} install -C ${WRKSRC}/Docs
.else
	${GMAKE} install -C ${WRKSRC}/Docs/man
.endif
	${INSTALL_DATA} ${WRKSRC}/Docs/sample/gnokiirc \
		${PREFIX}/etc/gnokiirc.sample
.if ${PORT_OPTIONS:MSMSD}
	@cd ${WRKSRC}/smsd && ${GMAKE} install
	${MKDIR} ${PREFIX}/share/smsd
	${INSTALL_SCRIPT} ${WRKSRC}/smsd/action ${PREFIX}/share/smsd
	${INSTALL_DATA} ${WRKSRC}/smsd/README ${PREFIX}/share/smsd
.  if ${PORT_OPTIONS:MMYSQL}
	${INSTALL_DATA} ${WRKSRC}/smsd/sms.tables.mysql.sql ${PREFIX}/share/smsd
.  endif
.  if ${PORT_OPTIONS:MPGSQL}
	${INSTALL_DATA} ${WRKSRC}/smsd/sms.tables.pq.sql ${PREFIX}/share/smsd
.  endif
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
