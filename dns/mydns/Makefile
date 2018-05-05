# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=	mydns
PORTVERSION=	1.1.0
PORTREVISION=	7
CATEGORIES=	dns databases
MASTER_SITES=	http://mydns.bboy.net/download/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	DNS server designed to utilize the MySQL database

LICENSE=	GPLv2

OPTIONS_DEFINE=	ALIAS OPENSSL PGSQL NLS DOCS NLS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc
USES=		tar:bzip2 iconv

USE_RC_SUBR=	mydns

SUB_FILES=	pkg-message

INFO=		mydns

DOCS=		AUTHORS COPYING ChangeLog NEWS QUICKSTART.mysql QUICKSTART.postgres README TODO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALIAS}
CONFIGURE_ARGS+=--enable-alias
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USES+=		ssl
CONFIGURE_ARGS+=--with-openssl \
		--with-openssl-include=${OPENSSLINC} \
		--with-openssl-lib=${OPENSSLLIB}
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
CONFIGURE_ARGS+=--without-mysql \
		--with-pgsql-include=${LOCALBASE}/include \
		--with-pgsql-lib=${LOCALBASE}/lib
PKGNAMESUFFIX=	-pg
.else
CONFIGURE_ARGS+=--without-pgsql \
		--with-mysql-include=${LOCALBASE}/include/mysql \
		--with-mysql-lib=${LOCALBASE}/lib/mysql
PKGNAMESUFFIX=	-mysql
USE_MYSQL=	yes
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/contrib
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.php ${STAGEDIR}${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.pl ${STAGEDIR}${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.pm ${STAGEDIR}${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/README ${STAGEDIR}${DOCSDIR}/contrib/
.endif
	@${STAGEDIR}${PREFIX}/sbin/mydns --dump-config > ${STAGEDIR}${PREFIX}/etc/mydns.conf.sample

.include <bsd.port.mk>
