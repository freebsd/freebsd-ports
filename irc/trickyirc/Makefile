# Created by: Adam Strohl <troll@digitalspark.net>
# $FreeBSD$

PORTNAME=	trickyirc
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://www.leb.net/~troll/
DISTNAME=	TrickyIRC-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Client-independent detaching and reattaching of IRC sessions

USES=		gmake
MAKEFILE=	GNUmakefile
MAKE_ARGS=	CC="${CC}" OPTCC_OPTS="${CFLAGS}"
WRKSRC=		${WRKDIR}/trickyirc

.if defined(BATCH) || defined(PACKAGE_BUILDING)
MAKE_ARGS+=	VERBOSE=YES
.endif

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

# Use better make(1) syntax in attempt to fix parallel (-jX) builds; do not
# explicitly set MAKE, it's a builtin variable that make(1) must set itself
post-patch:
	@${REINPLACE_CMD} -E \
		's/cd (.+); gmake \$$@; cd \.\./$$(MAKE) -C \1 $$@/' \
			${WRKSRC}/core/make/project.mk
	@${REINPLACE_CMD} -e '/MAKE=/d' ${WRKSRC}/core/make/platforms.mk

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config.sample ${EXAMPLESDIR}
.endif
	@${STRIP_CMD} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
