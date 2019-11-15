# Created by: Nadelyaev Stanislav <funkblaster@n11.bmstu.ru>
# $FreeBSD$

PORTNAME=		icegenerator
DISTVERSION=		0.5.5-pre2
PORTREVISION=		2
CATEGORIES=		audio net
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/0.5.5-pre2

MAINTAINER=		funkblaster@mail.ru
COMMENT=		Direct streaming generator for Icecast/Shoutcast

LIB_DEPENDS=		libshout.so:audio/libshout

GNU_CONFIGURE=		yes
USES=			gmake pkgconfig
CONFIGURE_ARGS=		--exec-prefix=${PREFIX}

OPTIONS_DEFINE=		DOCS MYSQL PGSQL

MYSQL_USES=	mysql
MYSQL_CONFIGURE_ON=	--with-mysql
PGSQL_USES=	pgsql
PGSQL_CONFIGURE_ON=	--with-pgsql

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/icegenerator.conf.dist \
		${STAGEDIR}${PREFIX}/etc/icegenerator.conf.sample

.include <bsd.port.mk>
