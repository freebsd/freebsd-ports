# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcfg
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://platon.sk/upload/_projects/00003/
DISTNAME=	${PORTNAME}+-${DISTVERSION}

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Library for command line and configuration file parsing

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.if !defined(NO_INSTALL_MANPAGES)
MAN3=		cfg_add_property.3 cfg_context.3 cfg_option.3 cfg_parse.3 \
		cfg_print_error.3 cfg_set_context_flag.3 libcfg+.3
MANCOMPRESSED=	yes
INSTALL_TARGET+=	install-man
.endif

PORTDOCS=	*

OPTIONS_DEFINE=	EXAMPLES DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/examples/example.* ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for FILE in AUTHORS README TODO
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/html
	@for FILE in ${WRKSRC}/doc/html/*; do \
		${INSTALL_DATA} $${FILE} ${DOCSDIR}/html; \
	done
.endif

.include <bsd.port.mk>
