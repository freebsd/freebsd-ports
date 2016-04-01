# Created by: FUJISHIMA Satsuki <sf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	navi2ch
PORTVERSION=	2.0.0.d
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	japanese www elisp
MASTER_SITES=	http://people.allbsd.org/~hrs/FreeBSD/ LOCAL/hrs
DISTNAME=	navi2ch-git-75ceac8e93d8d7cc02cc8fa44f14cd44ce0b9d0a
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	2ch.net and 2ch-like BBS navigator for Emacsen

LICENSE=	GPLv2

USES=		zip
USE_EMACS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	EMACS="${EMACS_CMD}"
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/${LISPDIR}/${PORTNAME}
PLIST_SUB=	LISPDIR=${LISPDIR}
PORTDOCS=	${PORTDOC_FILES} contrib

INFO=		navi2ch

PORTDOC_FILES=	ChangeLog README TODO
PORTDOC_LISPS=	gikope.el navi2ch-logo.el navi2ch-migemo.el
LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}

OPTIONS_DEFINE=	DOCS X11
OPTIONS_DEFAULT=DOCS X11
X11_RUN_DEPENDS=${LOCALBASE}/share/mona/monak12.pcf.gz:japanese/font-mona

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
	    ${INSTALL_DATA} ${PORTDOC_FILES} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/contrib
	cd ${WRKSRC}/contrib && \
	    ${INSTALL_DATA} ${PORTDOC_LISPS} ${STAGEDIR}${DOCSDIR}/contrib

.include <bsd.port.mk>
