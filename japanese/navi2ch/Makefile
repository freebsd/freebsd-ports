PORTNAME=	navi2ch
PORTVERSION=	2.0.0.d
PORTREVISION=	28
PORTEPOCH=	1
CATEGORIES=	japanese www elisp

MAINTAINER=	mce@FreeBSD.org
COMMENT=	2ch.net and 2ch-like BBS navigator for Emacsen
WWW=		https://navi2ch.sourceforge.net

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	proxy2ch:japanese/proxy2ch

USES=		emacs:build
USE_GITHUB=	yes
GH_ACCOUNT=	naota
GH_TAGNAME=	7811dba

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-icondir=${PREFIX}/${NICONDIR} \
		--with-lispdir=${PREFIX}/${NLISPDIR}
CONFIGURE_ENV=	EMACS="${EMACS_CMD}"

NO_ARCH=	yes

INFO=		${PORTNAME}
PLIST_SUB=	NICONDIR=${NICONDIR} NLISPDIR=${NLISPDIR}
PORTDOCS=	${PORTDOC_FILES} contrib

PORTDOC_FILES=	ChangeLog README TODO
PORTDOC_LISPS=	gikope.el navi2ch-logo.el navi2ch-migemo.el
NICONDIR=	${EMACS_LIBDIR}/etc/${PORTNAME}/icons
NLISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS X11
X11_RUN_DEPENDS=${LOCALBASE}/share/fonts/mona/monak12.pcf.gz:japanese/font-mona

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOC_FILES} ${PORTDOC_LISPS:S,^,contrib/,}" \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
