# Created by: Ka Ho Ng <khng300@gmail.com>
# $FreeBSD$

PORTNAME=	rime-data
PORTVERSION=	g20201216
CATEGORIES=	chinese textproc

MAINTAINER=	khng300@gmail.com
COMMENT=	Rime data files preset

LICENSE=	LGPL3

RUN_DEPENDS=	\
	${LOCALBASE}/share/rime-data/luna_pinyin.schema.yaml:chinese/rime-luna-pinyin	\
	${LOCALBASE}/share/rime-data/bopomofo.schema.yaml:chinese/rime-bopomofo	\
	${LOCALBASE}/share/rime-data/cangjie5.schema.yaml:chinese/rime-cangjie	\
	${LOCALBASE}/share/rime-data/stroke.schema.yaml:chinese/rime-stroke

USES=		localbase metaport

.include <bsd.port.mk>
