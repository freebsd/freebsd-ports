# $FreeBSD$

PORTNAME=	ruby
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	irc ruby
MASTER_SITES=	SF/xchat-${PORTNAME}/xchat-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	xchat-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby-scripting plugin for XChat

RUN_DEPENDS=	xchat:irc/xchat
LIB_DEPENDS=	lib${RUBY_NAME}.so:${RUBY_PORT}

LICENSE=	GPLv2

USE_RUBY=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
DOCSRC=		${WRKDIR}/${DISTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PLIST_FILES=	lib/xchat/plugins/xchat-ruby.so
PORTDOCS=	README ChangeLog
PORTEXAMPLES=	embedify.rb TimerSample.rb JFilter.rb JBanner.rb

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} \
		-e 's|^RUBY=.*|RUBY=${RUBY}|' \
		-e 's|-lruby$$|-l${RUBY_NAME}|' \
		-e 's|^ARCHDIR=.*|ARCHDIR=`$$(RUBY) ${FILESDIR}/rubypath.rb`|' \
		-e '/^CC=/s|gcc|${CC}|' \
		-e 's|^CFLAGS=|CFLAGS+=|' \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xchat/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/xchat-ruby.so \
		${STAGEDIR}${PREFIX}/lib/xchat/plugins/

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${DOCSRC}/,} ${STAGEDIR}${DOCSDIR}/

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${DOCSRC}/*/,} \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
