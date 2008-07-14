# New ports collection makefile for:    gnokii
# Date created:         15 March 1999
# Whom:                 staffanu
#
# $FreeBSD$
#

PORTNAME=	gnokii
PORTVERSION=	0.6.26
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.gnokii.org/download/gnokii/ \
		ftp://ftp.gnokii.org/pub/gnokii/ \
		http://www.gnokii.org/download/gnokii/0.6.x/

MAINTAINER=	mad@madpilot.net
COMMENT=	Tools to talk to GSM cellular phones

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE} --enable-security \
			--with-xgnokiidir=${PREFIX}/share
CONFIGURE_ENV+=	MSGFMT="${LOCALBASE}/bin/msgfmt" \
		XGETTEXT="${LOCALBASE}/bin/xgettext" \
		CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include -fPIC" \
		LIBS="-L../common -L${LOCALBASE}/lib" \
		PKG_CONFIG="${LOCALBASE}/bin/pkg-config"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PKGDEINSTALL=	${PKGINSTALL}
PKGMESSAGE=	${WRKDIR}/pkg-message

FIXPREFIX=	Docs/man/gnokiid.8 Docs/DataCalls-QuickStart Docs/README \
		common/cfgreader.c po/et.po po/sl.po

WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
MAN1=		gnokii.1 sendsms.1
MAN8=		gnokiid.8 mgnokiidev.8
PORTDOCS=	*
.endif

.if exists(${LOCALBASE}/lib/libical.so)
WITH_ICAL=	yes
.endif

.if exists(${LOCALBASE}/lib/libusb.so)
WITH_USB=	yes
.endif

.if exists(${LOCALBASE}/lib/libpcsclite.so) && !defined(WITHOUT_PCSC)
WITH_PCSC=	yes
.endif

.if defined(WITH_ICAL)
LIB_DEPENDS+=	ical.27:${PORTSDIR}/devel/libical
.endif

.if defined(WITH_USB)
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb

CONFIGURE_ARGS+=	--enable-libusb
.else
CONFIGURE_ARGS+=	--disable-libusb
.endif

.if defined(WITH_PCSC)
LIB_DEPENDS+=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

CONFIGURE_ARGS+=	--enable-libpcsclite
.else
CONFIGURE_ARGS+=	--disable-libpcsclite
.endif

# If smsd is enabled check if MySQL or PostgreSQL are installed and
# build the modules, no switches to make this port build those, if
# you want them, just install them before this port. The port will
# then activate a dependency.
.if !defined(WITH_SMSD)
PLIST_SUB+=	SMSD='@comment '
PLIST_SUB+=	PGM='@comment '
PLIST_SUB+=	MSM='@comment '
CONFIGURE_ARGS+=	--disable-smsd
.else
PLIST_SUB+=	SMSD=''
MAN8+=		smsd.8
USE_GNOME+=	glib20
.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so) && !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
PLIST_SUB+=	MSM=''
WITH_MYSQL=	yes
.else
PLIST_SUB+=	MSM='@comment '
.endif
.if exists(${LOCALBASE}/bin/psql) && !defined(WITHOUT_PGSQL)
USE_PGSQL=	yes
PLIST_SUB+=	PGM=''
WITH_PGSQL=	yes
.else
PLIST_SUB+=	PGM='@comment '
.endif
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11='@comment '
.else
USE_XORG=	xpm
USE_GNOME+=	glib20 gtk20 libgnome
PLIST_SUB+=	X11=''
.if !defined(NOPORTDOCS)
MAN1+=		xgnokii.1
.endif
.endif

pre-fetch:
.if !defined(WITH_SMSD)
	@${ECHO}
	@${ECHO} "If you plan using the smsd daemon for automatically receiving,"
	@${ECHO} "managing and sending SMSes define WITH_SMSD=yes."
	@${ECHO} "smsd has support for normal file system operations, MySQL and"
	@${ECHO} "PostgreSQL. If any of these 2 database systems are installed support"
	@${ECHO} "will be automatically compiled in. Normal file systems support is"
	@${ECHO} "always compiled in."
	@${ECHO}
.endif

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
# fix test conditions on configure
	@${REINPLACE_CMD} -E \
		-e 's|([[:space:]]+test[[:space:]]+.+)==([[:space:]]+"yes")|\1=\2|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${MV} ${WRKSRC}/Docs/man/xgnokii.1x ${WRKSRC}/Docs/man/xgnokii.1

post-build:
.if defined(WITH_SMSD)
.if defined(WITH_MYSQL)
	@${REINPLACE_CMD} -e 's/^#libsmsd_mysql_la_SOURCES/libsmsd_mysql_la_SOURCES/' ${WRKSRC}/smsd/Makefile.in
	@${REINPLACE_CMD} -e 's/^#libsmsd_mysql_la_LDFLAGS/libsmsd_mysql_la_LDFLAGS/' ${WRKSRC}/smsd/Makefile.in
	@${REINPLACE_CMD} -e 's/^#libsmsd_mysql_la_LIBADD/libsmsd_mysql_la_LIBADD/' ${WRKSRC}/smsd/Makefile.in
.endif
.if defined(WITH_PGSQL)
	@${REINPLACE_CMD} -e 's/^#libsmsd_pq_la_SOURCES/libsmsd_pq_la_SOURCES/' ${WRKSRC}/smsd/Makefile.in
	@${REINPLACE_CMD} -e 's/^#libsmsd_pq_la_LDFLAGS/libsmsd_pq_la_LDFLAGS/' ${WRKSRC}/smsd/Makefile.in
	@${REINPLACE_CMD} -e 's/^#libsmsd_pq_la_LIBADD/libsmsd_pq_la_LIBADD/' ${WRKSRC}/smsd/Makefile.in
.endif
.endif
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}

pre-install:
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/xgnokii/xgnokii.pc ${PREFIX}/libdata/pkgconfig
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/Docs && ${GMAKE} install)
.endif
	${INSTALL_DATA} ${WRKSRC}/Docs/sample/gnokiirc \
		${PREFIX}/etc/gnokiirc.sample
.if defined(WITH_SMSD)
	@cd ${WRKSRC}/smsd && ${GMAKE} install
	${MKDIR} ${PREFIX}/share/smsd
	${INSTALL_SCRIPT} ${WRKSRC}/smsd/action ${PREFIX}/share/smsd/action
	${INSTALL_DATA} ${WRKSRC}/smsd/README ${PREFIX}/share/smsd/README
.if defined(WITH_MYSQL)
	${INSTALL_DATA} ${WRKSRC}/smsd/sms.tables.mysql.sql ${PREFIX}/share/smsd/sms.tables.mysql.sql
.endif
.if defined(WITH_PGSQL)
	${INSTALL_DATA} ${WRKSRC}/smsd/sms.tables.pq.sql ${PREFIX}/share/smsd/sms.tables.pq.sql
.endif
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
