# Created by: Nadelyaev Stanislav <funkblaster@n11.bmstu.ru>
# $FreeBSD$

PORTNAME=		icegenerator
DISTVERSION=		0.5.5-pre2
CATEGORIES=		audio net
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/0.5.5-pre2

MAINTAINER=		funkblaster@mail.ru
COMMENT=		Direct streaming generator for Icecast/Shoutcast

LIB_DEPENDS=		libshout.so:${PORTSDIR}/audio/libshout2

GNU_CONFIGURE=		yes
USES=			gmake
CONFIGURE_ARGS=		--exec-prefix=${PREFIX}

OPTIONS_DEFINE=		DOCS MYSQL PGSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	YES
CONFIGURE_ARGS+=	--with-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	YES
CONFIGURE_ARGS+=	--with-pgsql
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/etc/icegenerator.conf.dist ${PREFIX}/etc
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
