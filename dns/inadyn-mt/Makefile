# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	inadyn-mt
PORTVERSION=	02.24.38
CATEGORIES=	dns
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}.v.${PORTVERSION}/
DISTNAME=	${PORTNAME}.v.${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Simple dynamic dns client

LICENSE=	GPLv3

USE_RC_SUBR=	inadyn-mt
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-sound

MAN8=		inadyn-mt.8
MAN5=		inadyn-mt.conf.5

PORTDOCS=	readme.html AUTHORS README
PORTEXAMPLES=	*

PLIST_DIRS=	etc/inadyn-mt/lang
PLIST_DIRSTRY=	etc/inadyn-mt
PLIST_FILES=	bin/inadyn-mt etc/inadyn-mt/lang/en.lng

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/man/inadyn-mt.8 ${WRKSRC}/readme.html \
		${WRKSRC}/src/dyndns.h

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/inadyn-mt.conf ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
