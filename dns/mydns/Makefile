# New ports collection makefile for:	mydns
# Date created:				23 July 2002
# Whom:					Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	mydns
PORTVERSION=	0.10.1
PORTREVISION=	1
CATEGORIES=	dns databases
MASTER_SITES=	http://mydns.bboy.net/download/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	DNS server designed to utilize the MySQL database

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc
USE_GETTEXT=	yes
USE_LIBTOOL=	yes
USE_BZIP2=	yes

INFO=		mydns
MAN5=		mydns.conf.5
MAN8=		mydns.8 mydnscheck.8 mydnsexport.8 mydnsimport.8 mydns-conf.8

DOCS=		AUTHORS COPYING ChangeLog NEWS QUICKSTART.mysql QUICKSTART.postgres README TODO

.if defined (WITH_ALIAS)
CONFIGURE_ARGS+=--enable-alias
.endif

.if defined (WITH_OPENSSL)
CONFIGURE_ARGS+=--with-openssl
.endif

.if defined (WITH_PGSQL)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql-client
CONFIGURE_ARGS+=--without-mysql
PKGNAMESUFFIX=	-pg
.else
CONFIGURE_ARGS+=--without-pgsql
PKGNAMESUFFIX=	-mysql
USE_MYSQL=	yes
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_PGSQL=yes          Build with PostgreSQL support"
	@${ECHO} "      WITH_ALIAS=yes          Enable server side aliases"
	@${ECHO} "      WITH_OPENSSL=yes        Enable OpenSSL (needed if MySQL is linked with OpenSSL)"
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

.include <bsd.port.mk>
