# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	esecanna-module-vje25
PORTVERSION=	0.14.6
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://esecanna.netfort.gr.jp/ \
		LOCAL/knu
DISTNAME=	${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	esecanna

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Esecanna module for VJE-Delta 2.5

RUN_DEPENDS=	${LOCALBASE}/sbin/esecannaserver:japanese/esecanna

GNU_CONFIGURE=	yes
USES=		gmake

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/esecanna
.for i in README CHANGES
	${INSTALL_DATA} ${WRKSRC}/${i}.jp \
		${STAGEDIR}${PREFIX}/share/doc/esecanna/${i}.vje25.jp
.endfor

.include <bsd.port.mk>
