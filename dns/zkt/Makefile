# Created by: Frank Behrens
# $FreeBSD$

PORTNAME=		zkt
DISTVERSION=		1.1.2
CATEGORIES=		dns
MASTER_SITES=		http://www.hznet.de/dns/zkt/

MAINTAINER=		frank@harz2014.behrens.de
COMMENT=		Tool to manage keys and signatures for DNSSEC-zones

DIR_NAMED_CONF?=	/etc/namedb

PLIST_FILES=		sbin/zkt-conf \
			sbin/zkt-keyman \
			sbin/zkt-ls \
			sbin/zkt-signer \
			sbin/zkt-soaserial
MAN8=			dnssec-zkt.8 \
			zkt-conf.8 \
			zkt-keyman.8 \
			zkt-ls.8 \
			zkt-signer.8
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-configpath=${DIR_NAMED_CONF}

post-patch:
	@${REINPLACE_CMD} -e 's|/var/named/|${DIR_NAMED_CONF}/|g' ${WRKSRC}/man/*.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-conf ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-keyman ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-ls ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-signer ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-soaserial ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/man/dnssec-zkt.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/zkt-conf.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/zkt-keyman.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/zkt-ls.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/zkt-signer.8 ${PREFIX}/man/man8/

.include <bsd.port.mk>
