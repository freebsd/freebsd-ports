PORTNAME=	lrzsz
PORTVERSION=	0.13.1
PORTREVISION=	0
CATEGORIES=	comms
MASTER_SITES=	https://ohse.de/uwe/releases/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Receive/Send files via X/Y/ZMODEM protocol (unrestrictive)
WWW=		https://ohse.de/uwe/software/lrzsz.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe

CPE_VENDOR=	lrzsz_project

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls
# configure defines _POSIX_C_SOURCE, hiding S_IFMT on FreeBSD.
CFLAGS+=	-U_POSIX_C_SOURCE

CONFLICTS_INSTALL=	lrzip # bin/lrz

OPTIONS_DEFINE=	DOCS

DOCS1=		COMPATABILITY ChangeLog NEWS
DOCS2=		zmodemsnif.txt zmodem-zmtx-zmrx.txt zmodem-forsberg.txt \
		zmodem-wip.txt README

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS1} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${DOCS2} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
