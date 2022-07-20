PORTNAME=	libidn
DISTVERSION=	1.38
CATEGORIES=	dns
MASTER_SITES=	GNU

MAINTAINER=	gaod@hychen.org
COMMENT=	Internationalized Domain Names command line tool

LICENSE=	GPLv2+ LGPL3+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYINGv2
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LESSERv3

USES=		cpe gmake iconv libtool localbase makeinfo pathfix perl5 pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_PERL5=	build

CPE_VENDOR=	gnu

INFO=		libidn

OPTIONS_DEFINE=	DOCS NLS

OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
