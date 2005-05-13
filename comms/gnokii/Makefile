# New ports collection makefile for:    gnokii
# Date created:         15 March 1999
# Whom:                 staffanu
#
# $FreeBSD$
#

PORTNAME=	gnokii
PORTVERSION=	0.6.5
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		http://www.gnokii.org/download/gnokii/0.6.x/ \
		ftp://ftp.gnokii.org/pub/gnokii/0.6.x/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mad@madpilot.net
COMMENT=	Tools to talk to GSM cellular phones

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE} --enable-security \
			--with-xgnokiidir=${PREFIX}/share
CONFIGURE_ENV+=	MSGFMT="${LOCALBASE}/bin/msgfmt" \
		XGETTEXT="${LOCALBASE}/bin/xgettext" \
		CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include -fPIC" \
		LIBS="-L../common -L${LOCALBASE}/lib"

MAN1=	gnokii.1 todologo.1 ppm2nokia.1 sendsms.1
MAN8=	gnokiid.8 mgnokiidev.8

INSTALL_TARGET=	install-suid
PKGDEINSTALL=	${PKGINSTALL}
PKGMESSAGE=	${WRKDIR}/pkg-message

FIXPREFIX=	Docs/man/gnokiid.8 Docs/DataCalls-QuickStart Docs/README \
		common/cfgreader.c po/et.po po/sl.po

WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libical.so.0)
WITH_ICAL=	yes
.endif

.if defined(WITH_ICAL)
LIB_DEPENDS+=	ical.0:${PORTSDIR}/devel/libical
.endif

.if ${OSVERSION} < 500000
LIB_DEPENDS+=	krb5:${PORTSDIR}/security/heimdal
.endif

# If smsd is enabled check if MySQL or PostgreSQL are installed and
# build the modules, no switches to make this port build those, if
# you want them, just install them before this port. The port will
# then activate a dependency.
.if !defined(WITH_SMSD)
PLIST_SUB+=	SMSD='@comment '
PLIST_SUB+=	PGM='@comment '
PLIST_SUB+=	MSM='@comment '
.else
PLIST_SUB+=	SMSD=''
MAN8+=		smsd.8
.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so)
USE_MYSQL=	yes
PLIST_SUB+=	MSM=''
WITH_MYSQL=	yes
.else
PLIST_SUB+=	MSM='@comment '
.endif
.if exists(${LOCALBASE}/bin/psql)
USE_PGSQL=	yes
PLIST_SUB+=	PGM=''
WITH_PGSQL=	yes
.else
PLIST_SUB+=	PGM='@comment '
.endif
.if defined(SMSD_WITH_GLIB2)
USE_GNOME+=	glib20
.else
USE_GNOME+=	glib12
.endif
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11='@comment '
.else
USE_XPM=	yes
USE_GNOME+=	gtk12
PLIST_SUB+=	X11=''
MAN1+=	xgnokii.1
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
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
.if !defined(SMSD_WITH_GLIB2)
	@${ECHO}
	@${ECHO} "smsd defaults to using glib1, if you'd rather link with glib2
	@${ECHO} "define SMSD_WITH_GLIB2=yes"
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
.if ${OSVERSION} <= 500027
	@${FIND} ${WRKSRC} -type f -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} \
		-e 's|<stdint.h>|<inttypes.h>|'
.endif
.if defined(SMSD_WITH_GLIB2)
	@cd ${WRKSRC} && ${PATCH} -s <${PATCHDIR}/smsd-Makefile-WITH_GLIB.diff
.endif

post-build:
.if defined(WITH_SMSD)
	@cd ${WRKSRC}/smsd && ${GMAKE} all
	@cd ${WRKSRC}/smsd && ${GMAKE} libfile.la LOCALBASE=${LOCALBASE}
.if defined(WITH_MYSQL)
	@cd ${WRKSRC}/smsd && ${GMAKE} libmysql.la LOCALBASE=${LOCALBASE}
.endif
.if defined(WITH_PGSQL)
	@cd ${WRKSRC}/smsd && ${GMAKE} libpq.la LOCALBASE=${LOCALBASE}
.endif
.endif
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}

pre-install:
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} && ${GMAKE} install-docs)
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
