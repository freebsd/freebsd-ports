# Created by: Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>

PORTNAME=	gawk
PORTVERSION=	3.0.6
PORTREVISION=	1
CATEGORIES=	japanese lang
MASTER_SITES=	GNU

PATCH_SITES=	http://www.hinadori.atnifty.com/~wills/program/
PATCHFILES=	${PORTNAME}mb115.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ota@j.email.ne.jp
COMMENT=	GNU awk + multi-byte extension

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-bitops --enable-non-decimal-data
MAKE_JOBS_UNSAFE=	yes

CONFLICTS_INSTALL=	gawk # bin/gawk

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

OPTIONS_DEFINE=	DOCS

post-configure:
	@${REINPLACE_CMD} -E \
	'/(DEFPATH|sed )/!s,(bin|data|lib|info|man|libexec)dir\),DESTDIR\)$$\(&,g' \
		${WRKSRC}/Makefile ${WRKSRC}/doc/Makefile ${WRKSRC}/awklib/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} OREADME.MB README.MB ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
