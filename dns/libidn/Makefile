PORTNAME=	libidn
DISTVERSION=	1.44
CATEGORIES=	dns
MASTER_SITES=	GNU

MAINTAINER=	gaod@hychen.org
COMMENT=	Internationalized Domain Names command line tool
WWW=		https://www.gnu.org/software/libidn/

LICENSE=	GPLv2+ LGPL3+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYINGv2
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LESSERv3

USES=		cpe gmake iconv libtool localbase makeinfo pathfix perl5 pkgconfig
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INFO=		libidn

OPTIONS_DEFINE=	DOCS NLS

OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FAQ NEWS README:L:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
