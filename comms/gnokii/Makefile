# Created by: Staffan Ulfberg <staffanu@multivac.fatburen.org>
# $FreeBSD$

PORTNAME=	gnokii
PORTVERSION=	0.6.31
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.gnokii.org/download/gnokii/ \
		ftp://ftp.gnokii.org/pub/gnokii/ \
		http://www.gnokii.org/download/gnokii/0.6.x/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Tools to talk to GSM cellular phones

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

GROUPS=		${PORTNAME}
USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_CSTD=	gnu89
USE_GNOME=	glib20 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-security
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

SUB_FILES+=	pkg-message
PORTDOCS=	*

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

ICAL_CONFIGURE_ENABLE=	libical
ICAL_LIB_DEPENDS=	libical.so:devel/libical
USB_CONFIGURE_ENABLE=	libusb
PCSC_CONFIGURE_ENABLE=	libpcsclite
PCSC_LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MSMSD)
PLIST_SUB+=	SMSD='@comment ' MSM='@comment ' PGM='@comment ' SQLT='@comment '
CONFIGURE_ARGS+=	--disable-smsd
.else
PLIST_SUB+=	SMSD=''
. if ${PORT_OPTIONS:MMYSQL}
USES+=		mysql
PLIST_SUB+=	MSM=''
. else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=	MSM='@comment '
. endif
. if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
PLIST_SUB+=	PGM=''
. else
CONFIGURE_ARGS+=	--disable-postgres
PLIST_SUB+=	PGM='@comment '
. endif
. if ${PORT_OPTIONS:MSQLITE}
LIB_DEPENDS+=	libsqlite3.so:databases/sqlite3
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
	${INSTALL_DATA} ${WRKSRC}/xgnokii/xgnokii.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
.if ${PORT_OPTIONS:MDOCS}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install -C ${WRKSRC}/Docs
.else
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install -C ${WRKSRC}/Docs/man
.endif
	${INSTALL_DATA} ${WRKSRC}/Docs/sample/gnokiirc \
		${STAGEDIR}${PREFIX}/etc/gnokiirc.sample
.if ${PORT_OPTIONS:MSMSD}
	@cd ${WRKSRC}/smsd && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} install
	${MKDIR} ${STAGEDIR}${PREFIX}/share/smsd
	${INSTALL_SCRIPT} ${WRKSRC}/smsd/action ${STAGEDIR}${PREFIX}/share/smsd
	${INSTALL_DATA} ${WRKSRC}/smsd/README ${STAGEDIR}${PREFIX}/share/smsd
.  if ${PORT_OPTIONS:MMYSQL}
	${INSTALL_DATA} ${WRKSRC}/smsd/sms.tables.mysql.sql ${STAGEDIR}${PREFIX}/share/smsd
.  endif
.  if ${PORT_OPTIONS:MPGSQL}
	${INSTALL_DATA} ${WRKSRC}/smsd/sms.tables.pq.sql ${STAGEDIR}${PREFIX}/share/smsd
.  endif
.endif

.include <bsd.port.mk>
