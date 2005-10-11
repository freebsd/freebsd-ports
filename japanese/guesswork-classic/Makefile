# New ports collection makefile for:	ja-guesswork-classic
# Date created:		10 Oct 2005
# Whom:			Shinsuke Matsui (<smatsui@karashi.org>)
#
# $FreeBSD$
#

PORTNAME=	guesswork-classic
PORTVERSION=	0.0.3
CATEGORIES=	japanese devel
MASTER_SITES=	http://classic.guesswork.jp/download/files/

MAINTAINER=	smatsui@karashi.org
COMMENT=	A PHP lightweight framework

RUN_DEPENDS=	${LOCALBASE}/share/smarty/Smarty.class.php:${PORTSDIR}/www/smarty

NO_BUILD=	yes
USE_PHP=	yes
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message

PORTDOCS=	ChangeLog README LICENSE

post-extract:
	@${FIND} ${WRKSRC} -name '.cvsignore' -delete

do-install:
	${MKDIR} ${DATADIR}
.for DIR in lib test
	${CP} -Rp ${WRKSRC}/${DIR} ${DATADIR}
	${FIND} ${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for DIR in examples public_html smarty
	${CP} -Rp ${WRKSRC}/${DIR} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
