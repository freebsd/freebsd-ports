PORTNAME=	dynip
PORTVERSION=	0.0
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	dynip@a1poweruser.com
COMMENT=	Dynamic IP Address Updater
WWW=		http://dynip.sourceforge.net/

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dynip           \
		${STAGEDIR}${PREFIX}/bin

	${INSTALL_SCRIPT} ${WRKSRC}/dynip_rcd       \
		${STAGEDIR}${PREFIX}/etc/rc.d/dynip

	${INSTALL_MAN} ${WRKSRC}/dynip.8 \
		${STAGEDIR}${PREFIX}/share/man/man8

	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKSRC}/dynip_daily     \
		${STAGEDIR}${PREFIX}/etc/periodic/daily/dynip

.include <bsd.port.mk>
