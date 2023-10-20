PORTNAME=	geany-plugin-git-changebar
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugin: ${${GEANY_PLUGIN}_DESC}
WWW=		https://plugins.geany.org/git-changebar.html

LIB_DEPENDS=	libgit2.so:devel/libgit2

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../geany-plugins/files/Makefile.common"
.include <bsd.port.mk>
