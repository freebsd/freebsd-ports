# Created by: Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
# $FreeBSD$

PORTNAME=	less
PORTVERSION=	382.262.03.01
DISTVERSIONPREFIX=	v
CATEGORIES=	japanese

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Enhanced less(1) supporting iso-2022-jp and UTF-8

LICENSE=	GPLv2

USES=		desthack ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	hrs-allbsd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cs-regex
PORTDOCS=	README.iso README.iso.jp README.lesw.euc \
		README.regex README.regex.jp README.ext.jp
PLIST_FILES=	bin/jless bin/jlesskey bin/jlessecho \
		man/man1/jless.1.gz man/man1/jlesskey.1.gz

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
