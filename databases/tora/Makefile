# New ports collection makefile for:	tora
# Date created:				03 January 2002
# Whom:					anders
#
# $FreeBSD$
#

PORTNAME=	tora
DISTVERSION=	1.3.22
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for Oracle

BUILD_DEPENDS=	${ORACLE_HOME}/lib/libclntsh.a:${PORTSDIR}/databases/oracle8-client \
		cppunit-config:${PORTSDIR}/devel/cppunit
LIB_DEPENDS=	qscintilla.7:${PORTSDIR}/x11-toolkits/qscintilla	\
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	${ORACLE_HOME}/network/admin/tnsnames.ora:${PORTSDIR}/databases/oracle8-client

.if !defined(WITHOUT_MYSQL)
BUILD_DEPENDS+=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin
RUN_DEPENDS+=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin
.endif

.if !defined(WITHOUT_PGSQL)
BUILD_DEPENDS+=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlpsql.so:${PORTSDIR}/databases/qt-pgsql-plugin
RUN_DEPENDS+=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlpsql.so:${PORTSDIR}/databases/qt-pgsql-plugin
.endif

ORACLE_HOME?=	${LOCALBASE}/oracle8-client
ORACLE_VER=	8i	# Client version

USE_BZIP2=	yes
USE_AUTOTOOLS=	aclocal:110 automake:110 autoconf:261 autoheader:261 libtool:15
USE_QT_VER=	3
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-oracle=${ORACLE_HOME} --with-oci-version=${ORACLE_VER:U}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes

.if defined(WITHOUT_KDE)
CONFIGURE_ARGS+=	--without-kde
.else
USE_KDELIBS_VER=3
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS BUGS ChangeLog INSTALL NEWS README README.CODESTYLE\
		README.LICENSE TODO
INFO=		tora
.endif

PREFIX2FIX=	doc/help/preferences.texi src/toconfiguration.h

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600029
BUILD_DEPENDS+=	${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo
CONFIGURE_ENV+=	MAKEINFO=${LOCALBASE}/bin/makeinfo
.endif

run-autotools:
	(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ./autogen.sh)

pre-configure:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|'	\
		${WRKSRC}/config/m4/qtkde.m4
	${REINPLACE_CMD} -e 's|/etc/torarc|${PREFIX}/etc/torarc|'	\
		${PREFIX2FIX:S|^|${WRKSRC}/|}
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|test doc|test|' ${WRKSRC}/Makefile.am
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
