# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	esecanna-module-vje30
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://esecanna.netfort.gr.jp/ \
		LOCAL/knu
DISTNAME=	${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	esecanna

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Esecanna module for VJE-Delta 3.0

RUN_DEPENDS=	${LOCALBASE}/sbin/esecannaserver:japanese/esecanna

USES=		gmake perl5
GNU_CONFIGURE=	yes
# VJE-Delta 3.0 is installed under /usr/local fixedly
CONFIGURE_ARGS=	--with-vjecfgfile="/usr/local/etc/vje30/vje.cfg"

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} "s,!!PREFIX!!,${PREFIX},g;" ${WRKSRC}/README.jp

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/esecanna
.for i in README CHANGES
	${INSTALL_DATA} ${WRKSRC}/${i}.jp \
		${STAGEDIR}${PREFIX}/share/doc/esecanna/${i}.vje30.jp
.endfor

.include <bsd.port.mk>
