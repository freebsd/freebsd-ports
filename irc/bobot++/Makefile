# ex:ts=8
# New ports collection makefile for:	bobot++
# Date created:			Sep 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bobotpp
PORTVERSION=	2.2.3
CATEGORIES=	irc
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IRC bot written in C++

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS=	GUILE "Use Guile scripts" on

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

INFO=		bobot++
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GUILE)
CONFIGURE_ARGS+=	--disable-scripting
.else
LIB_DEPENDS+=	guile.21:${PORTSDIR}/lang/guile
CONFIGURE_ARGS+=	--enable-scripting
PLIST_FILES+=	share/guile/site/bobotpp/bot.scm \
		%%DATADIR%%/scripts/bobot-utils.scm
PLIST_DIRS+=	%%DATADIR%%/scripts \
		%%DATADIR%% \
		share/guile/site/bobotpp
PLIST_DIRSTRY+=	share/guile/site
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|std::snprintf|snprintf|g' ${WRKSRC}/source/Bot.C

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/documentation && ${INSTALL_DATA} *.html ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
