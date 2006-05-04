# New ports collection makefile for:	idnkit
# Date created:		19 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	idnkit
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	http://www.nic.ad.jp/ja/idn/idnkit/download/sources/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library to handle internationalized domain names

USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv=${LOCALBASE} \
		--enable-runidn \
		--enable-extra-ace

INSTALLS_SHLIB=	yes

MAN1=		idnconv.1 \
		runidn.1
MAN3=		libidnkit.3 \
		libidnkitlite.3
MAN5=		idn.conf.5 \
		idnalias.conf.5 \
		idnrc.5
MANCOMPRESSED=	no

DOCS_EN=	ChangeLog NEWS README
DOCS_JA=	README.ja

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|mode=link $$(LD)|mode=link $$(CC)|'

post-install:
	${INSTALL_DATA} ${WRKSRC}/tools/runidn/libidnkitres.la ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
