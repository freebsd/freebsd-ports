# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	libidn
DISTVERSION=	1.34
CATEGORIES=	dns
MASTER_SITES=	GNU

MAINTAINER=	gaod@hychen.org
COMMENT=	Internationalized Domain Names command line tool

LICENSE=	GPLv2+ LGPL3+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYINGv2
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LESSERv3

USES=		gmake iconv libtool localbase makeinfo pathfix perl5 pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_PERL5=	build

INFO=		libidn

OPTIONS_DEFINE=	DOCS NLS

OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} -e '/^Libs.private:/s/$$/ @LTLIBINTL@/' \
		${WRKSRC}/libidn.pc.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
