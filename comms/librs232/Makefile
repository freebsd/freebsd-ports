PORTNAME=	librs232
PORTVERSION=	20190531
CATEGORIES=	comms
DISTNAME=	RS-232
MASTER_SITES=	http://www.teuniz.net/RS-232/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Simple serial library
WWW=		https://www.teuniz.net/RS-232/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl.txt

USES=		uidfix
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

PORTEXAMPLES=	demo_rx.c demo_tx.c

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if defined(NO_PROFILE) || ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079 )
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc.txt ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
