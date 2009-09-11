# New ports collection makefile for:	gnokii
# Date created:				15 March 1999
# Whom:			Staffan Ulfberg <staffanu@multivac.fatburen.org>
#
# $FreeBSD$
#

PORTNAME=	gnokii
PORTVERSION=	0.6.28
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.gnokii.org/download/gnokii/ \
		ftp://ftp.gnokii.org/pub/gnokii/ \
		http://www.gnokii.org/download/gnokii/0.6.x/

MAINTAINER=	mad@madpilot.net
COMMENT=	Tools to talk to GSM cellular phones

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE} --enable-security \
			--with-xgnokiidir=${PREFIX}/share
CONFIGURE_ENV+=	MSGFMT="${LOCALBASE}/bin/msgfmt" \
		XGETTEXT="${LOCALBASE}/bin/xgettext" \
		CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include -fPIC" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-L${WRKSRC}/common -L${LOCALBASE}/lib" \
		PKG_CONFIG="${LOCALBASE}/bin/pkg-config"

PKGDEINSTALL=	${PKGINSTALL}
SUB_FILES+=	pkg-message
PORTDOCS=	*
MAN1=		gnokii.1 sendsms.1
MAN8=		gnokiid.8 mgnokiidev.8

CONFLICTS=	smstools-[0-9]* sendsms-[0-9]*

OPTIONS=	ICAL	"Build with IETF iCal support"		off \
		USB	"Build with libusb support"		off \
		PCSC	"Build with PC/SC-Lite support"		off \
		SMSD	"Enable smsd daemon"			off \
		MYSQL	"Enable MySQL support for smsd"		off \
		PGSQL	"Enable PostgreSQL support for smsd"	off \
		X11	"Build graphical version (xgnokii)"	on

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libical.so) || defined(WITH_ICAL)
LIB_DEPENDS+=	ical.43:${PORTSDIR}/devel/libical
.endif

.if ${OSVERSION} < 800069
. if exists(${LOCALBASE}/lib/libusb.so) || defined(WITH_USB)
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
. endif
.endif

.if exists(${LOCALBASE}/lib/libpcsclite.so) || defined(WITH_PCSC)
LIB_DEPENDS+=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
.endif

.if !defined(WITH_SMSD)
PLIST_SUB+=	SMSD='@comment ' MSM='@comment ' PGM='@comment '
CONFIGURE_ARGS+=	--disable-smsd
.else
PLIST_SUB+=	SMSD=''
USE_GNOME+=	glib20
MAN8+=		smsd.8
.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so) && !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
PLIST_SUB+=	MSM=''
.else
PLIST_SUB+=	MSM='@comment '
.endif
.if exists(${LOCALBASE}/bin/psql) && !defined(WITHOUT_PGSQL)
USE_PGSQL=	yes
PLIST_SUB+=	PGM=''
.else
PLIST_SUB+=	PGM='@comment '
.endif
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11='@comment '
.else
USE_XORG=	xpm
USE_GNOME+=	gtk20
PLIST_SUB+=	X11=''
MAN1+=		xgnokii.1
.endif

FIXPREFIX=	Docs/man/gnokiid.8 Docs/DataCalls-QuickStart Docs/README \
		common/cfgreader.c po/et.po po/sl.po
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

pre-install:
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/xgnokii/xgnokii.pc ${PREFIX}/libdata/pkgconfig
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	${GMAKE} install -C ${WRKSRC}/Docs
.else
	${GMAKE} install -C ${WRKSRC}/Docs/man
.endif
	${INSTALL_DATA} ${WRKSRC}/Docs/sample/gnokiirc \
		${PREFIX}/etc/gnokiirc.sample
.if defined(WITH_SMSD)
	@cd ${WRKSRC}/smsd && ${GMAKE} install
	${MKDIR} ${PREFIX}/share/smsd
	${INSTALL_SCRIPT} ${WRKSRC}/smsd/action ${PREFIX}/share/smsd
	${INSTALL_DATA} ${WRKSRC}/smsd/README ${PREFIX}/share/smsd
.if defined(WITH_MYSQL)
	${INSTALL_DATA} ${WRKSRC}/smsd/sms.tables.mysql.sql ${PREFIX}/share/smsd
.endif
.if defined(WITH_PGSQL)
	${INSTALL_DATA} ${WRKSRC}/smsd/sms.tables.pq.sql ${PREFIX}/share/smsd
.endif
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
