# Created by: Frank Behrens
# $FreeBSD$

PORTNAME=		zkt
DISTVERSION=		1.1.4
CATEGORIES=		dns
MASTER_SITES=		http://www.hznet.de/dns/zkt/

MAINTAINER=		frank@harz.behrens.de
COMMENT=		Tool to manage keys and signatures for DNSSEC-zones

LICENSE=		BSD3CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

BUILD_DEPENDS=		dnssec-signzone:dns/bind-tools
RUN_DEPENDS:=		${BUILD_DEPENDS}

DIR_NAMED_CONF?=	/etc/namedb
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-configpath=${DIR_NAMED_CONF}

post-patch:
	@${REINPLACE_CMD} -e 's|/var/named/|${DIR_NAMED_CONF}/|g' ${WRKSRC}/man/*.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-conf ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-keyman ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-ls ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-signer ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-soaserial ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/man/dnssec-zkt.8 ${STAGEDIR}${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/zkt-conf.8 ${STAGEDIR}${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/zkt-keyman.8 ${STAGEDIR}${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/zkt-ls.8 ${STAGEDIR}${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/zkt-signer.8 ${STAGEDIR}${PREFIX}/man/man8/

.include <bsd.port.mk>
