# Created by: FUJISHIMA Satsuki <sf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	navi2ch
PORTVERSION=	1.8.4
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	japanese www elisp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	2ch.net and 2ch-like BBS navigator for Emacsen

LICENSE=	GPLv2

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/local/monak12.pcf.gz:${PORTSDIR}/japanese/monafonts
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
	    ${INSTALL_DATA} ${PORTDOC_FILES} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/contrib
	cd ${WRKSRC}/contrib && \
	    ${INSTALL_DATA} ${PORTDOC_LISPS} ${STAGEDIR}${DOCSDIR}/contrib

.include <bsd.port.mk>
