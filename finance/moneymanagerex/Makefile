# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mmex
PORTVERSION=	1.2.7
DISTVERSIONPREFIX=	v
PORTREVISION=	13
CATEGORIES=	finance
MASTER_SITES=	https://github.com/vslavik/bakefile/releases/download/v0.2.9/:bakefile
DISTFILES=	bakefile-0.2.9${EXTRACT_SUFX}:bakefile

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, open-source, easy-to-use personal finance software

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	moneymanagerex
GH_PROJECT=	moneymanagerex
GH_TUPLE=	Regaddi:Chart.js:f13f99b:chart_js/3rd/Chart.js \
		FVANCOP:ChartNew.js:77e7f87:chartnew_js/3rd/ChartNew.js \
		diepes:sorttable.js:3c63cb0:sorttable_js/3rd/sorttable.js \
		utelle:wxsqlite3:v3.3.1:wxsqlite3/lib/wxsqlite3 \
		moneymanagerex:database:5d7129f:database/database \
		moneymanagerex:LuaGlue:c51d11a:luaglue/3rd/LuaGlue \
		moneymanagerex:cajun:3684900:cajun/3rd/cajun \
		moneymanagerex:html-template:cd434ee:html_template/3rd/cgitemplate \
		moneymanagerex:csv-parser:ca3f0d7:csv_parser/3rd/csv-parser \
		moneymanagerex:ctpp:20158e0:ctpp/3rd/ctpp \
		moneymanagerex:mongoose:97583a6:mongoose/3rd/mongoose

USES=		autoreconf compiler:c++11-lib gettext gmake lua pkgconfig
GNU_CONFIGURE=	yes
USE_WX=		3.0
WX_CONF_ARGS=	absolute
INSTALLS_ICONS=	yes
USE_CXXSTD=	c++11

CPPFLAGS+=	-I${LOCALBASE}/include \
		-DHAVE_ACOSH \
		-DHAVE_ASINH \
		-DHAVE_ATANH \
		-DHAVE_ISBLANK \
		$$(pkg-config --cflags lua-${LUA_VER})
LDFLAGS+=	-L${LOCALBASE}/lib $$(pkg-config --libs lua-${LUA_VER})
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "gcc"
CXXFLAGS+=	-D_GLIBCXX_USE_C99
BUILD_DEPENDS+=	${LOCALBASE}/include/boost/lexical_cast.hpp:devel/boost-libs
.endif

post-extract:
	@${MV} ${WRKDIR}/bakefile-0.2.9/autoconf/*.m4 ${WRKSRC}/m4

post-patch:
	@${REINPLACE_CMD} -e \
		's|\*.txt|contrib.txt version.txt| ; \
		 s|-I$$(srcdir)/lib/lua/src || ; \
		 s|$$(LIBPREFIX)lua$$(LIBEXT) || ; \
		 s|-llua || ; \
		 s|$$(datadir)/man|$$(prefix)/man| ; \
		 s|-ldl$$||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^AC_INIT/s|1.2.3|${PORTVERSION}| ; \
		 s|\[noext\]|[]|' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		's| -g0 -O2||' ${WRKSRC}/m4/wxpresets.m4

.include <bsd.port.post.mk>
