# $FreeBSD$

PORTNAME=	ruby
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	irc ruby
MASTER_SITES=	SF/xchat-${PORTNAME}/xchat-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	xchat-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An ruby-scripting plugin for XChat

RUN_DEPENDS=	xchat:${PORTSDIR}/irc/xchat

LICENSE=	GPLv2

USE_RUBY=	yes
USE_LIBRUBY=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
DOCSRC=		${WRKDIR}/${DISTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PLIST_FILES=	lib/xchat/plugins/xchat-ruby.so
PORTDOCS=	README ChangeLog
PORTEXAMPLES=	embedify.rb TimerSample.rb JFilter.rb JBanner.rb

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} \
		-e 's|^RUBY=.*|RUBY=${RUBY}|' \
		-e 's|-lruby$$|-l${RUBY_NAME}|' \
		-e 's|^ARCHDIR=.*|ARCHDIR=`$$(RUBY) ${FILESDIR}/rubypath.rb`|' \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xchat/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/xchat-ruby.so \
		${STAGEDIR}${PREFIX}/lib/xchat/plugins/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${DOCSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${DOCSRC}/*/,} \
		${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
