# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=	mydns-ng
PORTVERSION=	1.2.8.31
PORTREVISION=	5
CATEGORIES=	dns databases
MASTER_SITES=	SF/${PORTNAME}/mydns/${PORTVERSION}
DISTNAME=	mydns-${PORTVERSION}

MAINTAINER=	gaod@hychen.org
COMMENT=	Next Generation DNS Server for sql based DNS services

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc
USES=		iconv
USE_RC_SUBR=	mydns
SUB_FILES=	pkg-message
INFO=		mydns
DOCS=		AUTHORS COPYING ChangeLog NEWS QUICKSTART.mysql QUICKSTART.postgres README TODO

OPTIONS_DEFINE=		DOCS ALIAS SSL NLS
OPTIONS_SINGLE=		DATABASE
OPTIONS_SINGLE_DATABASE=	PGSQL MYSQL
OPTIONS_DEFAULT=	ALIAS MYSQL
OPTIONS_SUB=	yes

ALIAS_DESC=	Server side aliasas

ALIAS_CONFIGURE_ENABLE=	alias

SSL_USES=		ssl
SSL_CONFIGURE_ON=	--with-openssl \
			--with-openssl-include=${OPENSSLINC} \
			--with-openssl-lib=${OPENSSLLIB}

PGSQL_USES=	pgsql
PGSQL_CONFIGURE_ON=	--with-pgsql \
			--with-pgsql-include=${LOCALBASE}/include \
			--with-pgsql-lib=${LOCALBASE}/lib
PGSQL_CONFIGURE_OFF=	--without-pgsql

MYSQL_USES=	mysql
MYSQL_CONFIGURE_ON=	--with-mysql \
			--with-mysql-include=${LOCALBASE}/include/mysql \
			--with-mysql-lib=${LOCALBASE}/lib/mysql
MYSQL_CONFIGURE_OFF=	--without-mysql

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/contrib
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.php ${STAGEDIR}${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.pl ${STAGEDIR}${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.pm ${STAGEDIR}${DOCSDIR}/contrib/
	@${INSTALL_DATA} ${WRKSRC}/contrib/README ${STAGEDIR}${DOCSDIR}/contrib/
	@${STAGEDIR}${PREFIX}/sbin/mydns --dump-config > ${STAGEDIR}${PREFIX}/etc/mydns.conf.sample

.include <bsd.port.mk>
