PORTNAME=	gnokii
PORTVERSION=	0.6.31
PORTREVISION=	16
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.gnokii.org/download/gnokii/ \
		http://www.gnokii.org/download/gnokii/0.6.x/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Tools to talk to GSM cellular phones
WWW=		https://www.gnokii.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

GROUPS=		${PORTNAME}
USES=		gettext gmake gnome iconv libtool localbase pathfix pkgconfig \
		readline shebangfix tar:bzip2
USE_LDCONFIG=	yes
USE_CSTD=	gnu89
USE_GNOME=	glib20 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-security
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
SHEBANG_FILES=	smsd/action

SUB_FILES=	pkg-message
PORTDOCS=	*

CONFLICTS=	smstools sendsms

FIXPREFIX=	Docs/README common/cfgreader.c

OPTIONS_DEFINE=	DOCS ICAL PCSC SMSD USB X11
OPTIONS_GROUP=	SMSDDB
OPTIONS_GROUP_SMSDDB=	MYSQL PGSQL SQLITE
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
MYSQL_IMPLIES=		SMSD
PGSQL_IMPLIES=		SMSD
SQLITE_IMPLIES=		SMSD
SMSD_PLIST_SUB=		SMSD=''
SMSD_PLIST_SUB_OFF=	SMSD='@comment ' MSM='@comment ' PGM='@comment ' SQLT='@comment '
SMSD_CONFIGURE_OFF=	--disable-smsd
MYSQL_USES=		mysql ssl
MYSQL_PLIST_SUB=	MSM=''
MYSQL_PLIST_SUB_OFF=	MSM='@comment '
MYSQL_CONFIGURE_OFF=	--disable-mysql
MYSQL_VARS=		IGNORE_WITH_MYSQL="80 81"
PGSQL_USES=		pgsql
PGSQL_PLIST_SUB=	PGM=''
PGSQL_PLIST_SUB_OFF=	PGM='@comment '
PGSQL_CONFIGURE_OFF=	--disable-postgres
SQLITE_USES=		sqlite
SQLITE_PLIST_SUB=	SQLT=''
SQLITE_PLIST_SUB_OFF=	SQLT='@comment '
SQLITE_CONFIGURE_OFF=	--disable-sqlite
X11_CONFIGURE_WITH=	x
X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz
X11_USES=		xorg
X11_USE=		XORG=x11 XORG=xpm \
			GNOME=cairo GNOME=gdkpixbuf GNOME=gtk20
X11_PLIST_SUB=		X11=''
X11_PLIST_SUB_OFF=	X11='@comment '

post-patch:
.for f in ${FIXPREFIX}
	@${REINPLACE_CMD} -e "s:/etc/gnokiirc:${PREFIX}/etc/gnokiirc:g" \
		${WRKSRC}/${f}
.endfor
.for f in common/data/virtmodem.c utils/mgnokiidev.c
	@${REINPLACE_CMD} -E -e "s:^(#ifdef.*)__OpenBSD__:\1__FreeBSD__:" \
		${WRKSRC}/${f}
.endfor
	@${MV} ${WRKSRC}/Docs/man/xgnokii.1x ${WRKSRC}/Docs/man/xgnokii.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/xgnokii/xgnokii.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/Docs/sample/gnokiirc \
		${STAGEDIR}${PREFIX}/etc/gnokiirc.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnokii.so.7.0.0

post-install-DOCS-on:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install -C ${WRKSRC}/Docs

post-install-DOCS-off:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install -C ${WRKSRC}/Docs/man

post-install-SMSD-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/smsd
	@cd ${WRKSRC}/smsd && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install
	${INSTALL_SCRIPT} ${WRKSRC}/smsd/action ${STAGEDIR}${PREFIX}/share/smsd
	${INSTALL_DATA} ${WRKSRC}/smsd/README ${STAGEDIR}${PREFIX}/share/smsd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/smsd/*.so

post-install-MYSQL-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/smsd
	${INSTALL_DATA} ${WRKSRC}/smsd/sms.tables.mysql.sql ${STAGEDIR}${PREFIX}/share/smsd

post-install-PGSQL-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/smsd
	${INSTALL_DATA} ${WRKSRC}/smsd/sms.tables.pq.sql ${STAGEDIR}${PREFIX}/share/smsd

.include <bsd.port.mk>
