# New ports collection makefile for:    gnokii
# Date created:         15 March 1999
# Whom:                 staffanu
#
# $FreeBSD$
#

PORTNAME=	gnokii
PORTVERSION=	0.5.8
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		ftp://ftp.pl.gnokii.org/pub/gnokii/ \
		ftp://ftp.gnokii.org/pub/gnokii/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools to talk to Nokia cellular phones

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE} --enable-security \
			--with-xgnokiidir=${PREFIX}/share
CONFIGURE_ENV+=	MSGFMT="${LOCALBASE}/bin/msgfmt" \
		XGETTEXT="${LOCALBASE}/bin/xgettext" \
		CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L../common -L${LOCALBASE}/lib"

MAN1=	gnokii.1 todologo.1 ppm2nokia.1 sendsms.1
MAN8=	gnokiid.8 mgnokiidev.8

INSTALL_TARGET=	install-suid
PKGDEINSTALL=	${PKGINSTALL}
PKGMESSAGE=	${WRKDIR}/pkg-message

FIXPREFIX=	Docs/man/gnokiid.8 Docs/DataCalls-QuickStart Docs/README \
		common/cfgreader.c po/et.po po/sl.po

.include <bsd.port.pre.mk>

# If smsd is enabled check if MySQL or PostgreSQL are installed and
# build the modules, no switches to make this port build those, if
# you want them, just install them before this port. The port will
# then activate a dependency.
.if !defined(WITH_SMSD)
PLIST_SUB+=	SMSD='@comment '
PLIST_SUB+=	PGM='@comment '
PLIST_SUB+=	MSM='@comment '
USE_GNOME+=	glib12
.else
PLIST_SUB+=	SMSD=''
.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so)
USE_MYSQL=	yes
PLIST_SUB+=	MSM=''
WITH_MYSQL=	yes
.else
PLIST_SUB+=	MSM='@comment '
.endif
.if exists(${LOCALBASE}/lib/libpq.so)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
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
USE_XPM=	yes
USE_GNOME+=	gtk12
PLIST_SUB+=	X11=''
MAN1+=	xgnokii.1
.endif

pre-fetch:
	@${ECHO}
	@${ECHO} "If you plan using the smsd daemon for automatically receiving,"
	@${ECHO} "managing and sending SMSes define WITH_SMSD=yes."
	@${ECHO} "smsd has support for normal file system operations, MySQL and"
	@${ECHO} "PostgreSQL. If any of these 2 database systems are installed support"
	@${ECHO} "will be automatically compiled in. Normal file systems support is"
	@${ECHO} "always compiled in."
	@${ECHO}

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

post-build:
.if defined(WITH_SMSD)
	@cd ${WRKSRC}/smsd && ${GMAKE} all
	@cd ${WRKSRC}/smsd && ${GMAKE} libfile.so LOCALBASE=${LOCALBASE}
.if defined(WITH_MYSQL)
	@cd ${WRKSRC}/smsd && ${GMAKE} libmysql.so LOCALBASE=${LOCALBASE}
.endif
.if defined(WITH_PGSQL)
	@cd ${WRKSRC}/smsd && ${GMAKE} libpq.so LOCALBASE=${LOCALBASE}
.endif
.endif
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' pkg-message > ${PKGMESSAGE}

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
	${MKDIR} ${PREFIX}/share/smsd
	${INSTALL_PROGRAM} ${WRKSRC}/smsd/smsd ${PREFIX}/sbin/smsd
	${INSTALL_SCRIPT} ${WRKSRC}/smsd/action ${PREFIX}/share/smsd/action
	${INSTALL_DATA} ${WRKSRC}/smsd/README ${PREFIX}/share/smsd/README
	${INSTALL_PROGRAM} ${WRKSRC}/smsd/libfile.so ${PREFIX}/share/smsd/libfile.so
.if defined(WITH_MYSQL)
	${INSTALL_PROGRAM} ${WRKSRC}/smsd/libmysql.so ${PREFIX}/share/smsd/libmysql.so
	${INSTALL_DATA} ${WRKSRC}/smsd/sms.tables.mysql.sql ${PREFIX}/share/smsd/sms.tables.mysql.sql
.endif
.if defined(WITH_PGSQL)
	${INSTALL_PROGRAM} ${WRKSRC}/smsd/libpq.so ${PREFIX}/share/smsd/libpq.so
	${INSTALL_DATA} ${WRKSRC}/smsd/sms.tables.pq.sql ${PREFIX}/share/smsd/sms.tables.pq.sql
.endif
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
