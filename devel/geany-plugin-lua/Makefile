PORTNAME=	geany-plugin-lua
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}

USES=		lua:51 shebangfix

SHEBANG_FILES=	geanylua/util/mkiface.lua \
		geanylua/util/mk-keytab.lua \
		geanylua/util/keywords.lua

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
