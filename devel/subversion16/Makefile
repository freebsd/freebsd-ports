# New ports collection makefile for:	subversion
# Date created:				10 September 2001
# Whom:					rooneg@electricjellyfish.net
#
# $FreeBSD$

PORTNAME=	subversion
PORTVERSION=	0.26.0
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/files/documents/15/5322/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=		bmah

MAINTAINER=	bmah@freebsd.org
COMMENT=	Version control system

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4 \
		neon.23:${PORTSDIR}/www/neon \
		expat.4:${PORTSDIR}/textproc/expat2

INSTALLS_SHLIB=	yes

WRKSRC=	${WRKDIR}/subversion-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-ssl \
		--with-neon=${LOCALBASE} \
		--with-berkeley-db=${LOCALBASE}/include/db4:${LOCALBASE}/lib \
		--with-swig=no

MAN1=	svn.1 svnadmin.1
MANCOMPRESSED=	no

APXS=${LOCALBASE}/sbin/apxs

.if defined(WITH_MOD_DAV_SVN)
WITH_APACHE2_APR=	yes
CONFIGURE_ARGS+= \
		--with-apxs=${APXS}
PLIST_SUB+=	MOD_DAV_SVN=""
.else
PLIST_SUB+=	MOD_DAV_SVN="@comment "
PKGDEINSTALL=	NONEXISTENT
.endif

.if defined(WITH_APACHE2_APR)
APACHE2_PORT?=	${PORTSDIR}/www/apache2
BUILD_DEPENDS+=	${APXS}:${APACHE2_PORT}
RUN_DEPENDS+=	${APXS}:${APACHE2_PORT}
CONFIGURE_ARGS+=--with-apr=${LOCALBASE}/lib/apache2/apr-config \
		--with-apr-util=${LOCALBASE}/lib/apache2/apu-config
.else
LIB_DEPENDS+=  apr-0.9:${PORTSDIR}/devel/apr
CONFIGURE_ARGS+=--with-apr=${LOCALBASE} \
		--with-apr-util=${LOCALBASE}
.endif

pre-extract:
.if defined(WITH_MOD_DAV_SVN)
	@${ECHO_MSG} "mod_dav_svn module for Apache 2.X enabled."
.else
	@${ECHO_MSG} "You can enable the mod_dav_svn module for Apache 2.X"
	@${ECHO_MSG} "by defining WITH_MOD_DAV_SVN.  This option implies"
	@${ECHO_MSG} "the WITH_APACHE2_APR option."
.endif
	@${ECHO_MSG}
.if defined(WITH_APACHE2_APR)
	@${ECHO_MSG} "Using APR from www/apache2.  If you have the devel/apr"
	@${ECHO_MSG} "port/package installed, you may need to remove it."
.else
	@${ECHO_MSG} "You can link subversion against the APR built with"
	@${ECHO_MSG} "the www/apache2 port, rather than the devel/apr port,"
	@${ECHO_MSG} "by defining WITH_APACHE2_APR."
.endif
	@${ECHO_MSG}

post-extract:
	@${REINPLACE_CMD} 's/ldb/ldb4/g' ${WRKSRC}/configure

	@${RM} -r ${WRKSRC}/neon
	@${RM} -r ${WRKSRC}/apr
	@${RM} -r ${WRKSRC}/apr-util

.if defined(WITH_MOD_DAV_SVN)
pre-install:
	${APXS} -e -S LIBEXECDIR=${PREFIX}/libexec/apache2 -a -n dav libexec/apache2/mod_dav.so
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for f in BUGS CHANGES COMMITTERS COPYING HACKING IDEAS INSTALL README; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

post-deinstall:
.if defined(WITH_MOD_DAV_SVN)
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} POST-DEINSTALL
.endif

.include <bsd.port.mk>
