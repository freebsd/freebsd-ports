# New ports collection makefile for:	qhacc
# Date created:		28 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	qhacc
PORTVERSION=	3.5
PORTREVISION=	5
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple QT-based financial manager

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_AUTOTOOLS=	libtool:22
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-moc=${QT_PREFIX}/bin \
		--with-qt-libs=${QT_PREFIX}/lib
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
USE_LDCONFIG=	yes

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--enable-mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--enable-psql
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	yes
CONFIGURE_ARGS+=	--enable-sqlite \
		--with-sqlite-libs="${LOCALBASE}/lib" \
		--with-sqlite-includes="${LOCALBASE}/include"
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if defined(WITH_GPGME)
LIB_DEPENDS+=	gpgme.18:${PORTSDIR}/security/gpgme
CONFIGURE_ARGS+=	--enable-gpg
PLIST_SUB+=	GPGME=""
.else
PLIST_SUB+=	GPGME="@comment "
.endif

.if defined(WITH_GENERATOR)
CONFIGURE_ARGS+=	--enable-generator
PLIST_SUB+=	GENERATOR=""
.else
PLIST_SUB+=	GENERATOR="@comment "
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "QHacc has the following tunable option(s):"
	@${ECHO_MSG}
	@${ECHO_MSG} "	WITH_MYSQL=yes		Turns on MySQL support"
	@${ECHO_MSG} "	WITH_PGSQL=yes		Turns on PostgreSQL support"
	@${ECHO_MSG} "	WITH_SQLITE=yes		Turns on SQLite support"
	@${ECHO_MSG} "	WITH_GPGME=yes		Turns on GnuPG support"
	@${ECHO_MSG} "	WITH_GENERATOR=yes	Turns on random-data generator support"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/src/qhacc.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's| -O2||g ; \
		 s| -g||g ; \
		 s| -pedantic||g'

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/qm/*.qm ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
.for file in accounts jobs journals namedtrans preferences splits transactions
	${INSTALL_DATA} ${WRKSRC}/contrib/easysetup/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
