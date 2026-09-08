PORTNAME=	eblook
DISTVERSION=	1.6.1
PORTREVISION=	11
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/
DIST_SUBDIR=	eb

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Command to lookup words in EB format dictionaries
WWW=		http://openlab.ring.gr.jp/edict/eblook/index.html.ja

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libeb.so:japanese/eb

USES=		gettext-runtime iconv
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-eb-conf=${PREFIX}/etc/eb.conf

INFO=		eblook
PLIST_FILES=	bin/eblook
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
