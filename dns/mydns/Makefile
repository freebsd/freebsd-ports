# New ports collection makefile for:	mydns
# Date created:				23 July 2002
# Whom:					Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	mydns
PORTVERSION=	0.10.0
PORTREVISION=	3
CATEGORIES=	dns databases
MASTER_SITES=	http://mydns.bboy.net/download/

MAINTAINER=	simond@irrelevant.org
COMMENT=	DNS server designed to utilize the MySQL database

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext \
		iconv.3:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc
USE_LIBTOOL=	yes
USE_BZIP2=	yes

INFO=		mydns
MAN5=		mydns.conf.5
MAN8=		mydns.8 mydnscheck.8 mydnsexport.8 mydnsimport.8 mydns-conf.8

DOCS=		AUTHORS COPYING ChangeLog NEWS QUICKSTART.mysql QUICKSTART.postgres README TODO

.include <bsd.port.pre.mk>

.if defined (WITH_ALIAS)
CONFIGURE_ARGS+=--enable-alias
.endif

.if defined (WITH_OPENSSL)
CONFIGURE_ARGS+=--with-openssl
.endif

.if defined (WITH_PGSQL)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=--without-mysql
PKGNAMESUFFIX=	-pg
.else
CONFIGURE_ARGS+=--without-pgsql
PKGNAMESUFFIX=	-mysql
.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.10)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.elif exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.14)
LIB_DEPENDS+=	mysqlclient.14:${PORTSDIR}/databases/mysql41-client
.else
LIB_DEPENDS+=	mysqlclient.12:${PORTSDIR}/databases/mysql40-client
.endif
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_PGSQL=yes          Build with PostgreSQL support"
	@${ECHO} "      WITH_ALIAS=yes          Enable server side aliases"
	@${ECHO} "      WITH_OPENSSL=yes        Enable OpenSSL (needed if MySQL is linked with OpenSSL"
	@${ECHO} ""

post-install:
	@${SED} 's|%%%PREFIX%%%|${PREFIX}|g' < ${FILESDIR}/mydns.sh > ${WRKSRC}/mydns.sh
	@${INSTALL_SCRIPT} ${WRKSRC}/mydns.sh ${PREFIX}/etc/rc.d/mydns.sh.sample
	@install-info ${PREFIX}/info/mydns.info ${PREFIX}/info/dir
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/contrib
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.php ${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/README ${DOCSDIR}/contrib/
.endif
	@${PREFIX}/sbin/mydns --dump-config >${PREFIX}/etc/mydns.conf.sample
	@${SED} -e 's,%%%PREFIX%%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
