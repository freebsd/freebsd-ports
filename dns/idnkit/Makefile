# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	idnkit
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	http://www.nic.ad.jp/ja/idn/idnkit/download/sources/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to handle internationalized domain names

USE_AUTOTOOLS=	libtool
USES=		iconv
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_BASE} \
		--enable-runidn \
		--enable-extra-ace

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|mode=link $$(LD)|mode=link $$(CC)|'

post-install:
	${INSTALL_DATA} ${WRKSRC}/tools/runidn/libidnkitres.la \
		${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
	(cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog NEWS README \
		${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/README.ja ${STAGEDIR}${DOCSDIR}/ja

.include <bsd.port.mk>
