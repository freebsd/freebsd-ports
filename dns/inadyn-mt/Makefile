# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	inadyn-mt
PORTVERSION=	02.24.38
CATEGORIES=	dns
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}.v.${PORTVERSION}/
DISTNAME=	${PORTNAME}.v.${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Simple dynamic dns client

USE_RC_SUBR=	inadyn-mt
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-sound

.if !defined(NO_INSTALL_MANPAGES)
MAN8=		inadyn-mt.8
MAN5=		inadyn-mt.conf.5
.endif

PORTDOCS=	readme.html
PLIST_FILES=	bin/inadyn-mt

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/man/inadyn-mt.8 ${WRKSRC}/readme.html \
		${WRKSRC}/src/dyndns.h

.include <bsd.port.options.mk>

do-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} -p ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/bin/freebsd/inadyn-mt ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/man/inadyn-mt.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/inadyn-mt.conf.5 ${MANPREFIX}/man/man5
.endif

.include <bsd.port.mk>
