PORTNAME=	jove
DISTVERSION=	4.17.5.5
CATEGORIES=	editors

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Jonathan's Own Version of Emacs
WWW=		https://github.com/jonmacs/jove

LICENSE=	BSD0CLAUSE

USES=		groff ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	jonmacs

pre-patch:
	${REINPLACE_CMD} -e 's,/usr/local/,${PREFIX}/,' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,/etc/,${PREFIX}/etc/,' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}/var/lib/jove/tmp
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/jove

.include <bsd.port.mk>
