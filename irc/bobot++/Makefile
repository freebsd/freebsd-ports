# Created by: ijliao
# $FreeBSD$

PORTNAME=	bobotpp
PORTVERSION=	2.2.3
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC bot written in C++

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	GUILE
OPTIONS_DEFAULT=	GUILE
GUILE_DESC=	Use Guile scripts

GNU_CONFIGURE=	yes

INFO=		bobot++
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUILE}
LIB_DEPENDS+=	libguile.so:${PORTSDIR}/lang/guile
CONFIGURE_ARGS+=	--enable-scripting
PLIST_FILES+=	share/guile/site/bobotpp/bot.scm \
		%%DATADIR%%/scripts/bobot-utils.scm
PLIST_DIRS+=	%%DATADIR%%/scripts \
		%%DATADIR%% \
		share/guile/site/bobotpp
PLIST_DIRSTRY+=	share/guile/site
.else
CONFIGURE_ARGS+=	--disable-scripting
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|std::snprintf|snprintf|g' ${WRKSRC}/source/Bot.C

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/documentation && ${INSTALL_DATA} *.html ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
