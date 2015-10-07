# Created by: Paul Chvostek <paul@it.ca>
# $FreeBSD$

PORTNAME=	rbldnsd
PORTVERSION=	0.997a
CATEGORIES=	dns
MASTER_SITES=	http://www.corpit.ru/mjt/rbldnsd/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Small and fast DNS daemon especially for DNSBL zones

LICENSE=	GPLv2

ROOTDIR=	${STAGEDIR}${PREFIX}/etc/rbldnsd

HAS_CONFIGURE=	yes
USE_RC_SUBR=	rbldnsd
USERS=		rbldns
GROUPS=		${USERS}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	if [ ! -d ${ROOTDIR} ]; then \
		${INSTALL} -d -m 710 ${ROOTDIR}; \
	fi
	${INSTALL_DATA} -m 640 \
		${FILESDIR}/example ${ROOTDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/rbldnsd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/rbldnsd.8 ${STAGEDIR}${PREFIX}/man/man8

do-install-DOCS-on:
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES-0.81 ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/copyright ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/rbldnsd.default ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/rbldnsd.init ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/rbldnsd.spec ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
