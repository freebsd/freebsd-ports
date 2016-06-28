# Created by: Shinsuke Matsui (<smatsui@karashi.org>)
# $FreeBSD$

PORTNAME=	guesswork-classic
PORTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	japanese devel
MASTER_SITES=	http://classic.guesswork.jp/download/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP lightweight framework

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

RUN_DEPENDS=	${LOCALBASE}/share/smarty/Smarty.class.php:www/smarty2

NO_BUILD=	yes
USES=		php:web

SUB_FILES=	pkg-message

PORTDOCS=	ChangeLog README LICENSE
OPTIONS_DEFINE=	DOCS

post-extract:
	@${FIND} ${WRKSRC} -name '.cvsignore' -delete

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.for DIR in lib test
	${CP} -Rp ${WRKSRC}/${DIR} ${STAGEDIR}${DATADIR}
	${FIND} ${STAGEDIR}${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for DIR in examples public_html smarty
	${CP} -Rp ${WRKSRC}/${DIR} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
