PORTNAME=	jove
DISTVERSION=	4.17.5.3
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

post-install:
	@${MKDIR} ${STAGEDIR}/var/lib/jove/tmp

.include <bsd.port.mk>
