# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=	mydns-ng
PORTVERSION=	1.2.8.31
PORTREVISION=	2
CATEGORIES=	dns databases
MASTER_SITES=	SF/${PORTNAME}/mydns/${PORTVERSION}
DISTNAME=	mydns-${PORTVERSION}

MAINTAINER=	gaod@hychen.org
COMMENT=	Next Generation DNS Server for sql based DNS services

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc
USES=		iconv
USE_RC_SUBR=	mydns
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
INFO=		mydns
DOCS=		AUTHORS COPYING ChangeLog NEWS QUICKSTART.mysql QUICKSTART.postgres README TODO

OPTIONS_DEFINE=		DOCS PGSQL ALIAS SSL NLS
OPTIONS_DEFAULT=	ALIAS
ALIAS_DESC=	Server side aliasas
ALIAS_CONFIGURE_ENABLE=	alias

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=yes
CONFIGURE_ARGS+=--with-openssl \
		--with-openssl-include=${OPENSSLINC} \
		--with-openssl-lib=${OPENSSLLIB}
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--without-mysql \
		--with-pgsql-include=${LOCALBASE}/include \
		--with-pgsql-lib=${LOCALBASE}/lib
PKGNAMESUFFIX=	-pgsql
.else
CONFIGURE_ARGS+=--without-pgsql \
		--with-mysql-include=${LOCALBASE}/include/mysql \
		--with-mysql-lib=${LOCALBASE}/lib/mysql
PKGNAMESUFFIX=	-mysql
USE_MYSQL=	yes
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
CONFIGURE_ARGS+=--with-included-gettext
USES+=		gettext
PLIST_SUB+=	NLS=""
.endif

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
