# Created by: dglo@ssec.wisc.edu
# $FreeBSD$

PORTNAME=	nslint
PORTVERSION=	3.1
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.ee.lbl.gov/ \
		CRITICAL
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/a/}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perform consistency checks on DNS zone files

GNU_CONFIGURE=	yes

ALL_TARGET=	${PORTNAME}

BOOTFILE?=	/etc/namedb/named.boot
CONFFILE?=	/etc/namedb/named.conf

PLIST_FILES=	bin/nslint man/man8/nslint.8.gz

post-patch:
	@${REINPLACE_CMD} -e '/^\ \{4\}V_CCOPT/d' ${WRKSRC}/configure
	@@${REINPLACE_CMD} -e 's|/etc/named.boot|${BOOTFILE}|; \
		s|/etc/named.conf|${CONFFILE}|' \
			${WRKSRC}/${PORTNAME}.c \
			${WRKSRC}/${PORTNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nslint ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nslint.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
