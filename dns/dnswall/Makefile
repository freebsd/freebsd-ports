# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnswall
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	dns security
MASTER_SITES=	GOOGLE_CODE CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Daemon that filters out private IP addresses in DNS responses

USES=		dos2unix
PROJECTHOST=	google-dnswall
USE_AUTOTOOLS=	automake autoconf:env

WRKSRC=		${WRKDIR}/${PORTNAME}

AUTOFILES=	depcomp install-sh missing

PORTDOCS=	README
PLIST_FILES=	bin/dnswall

AUTOTOOLSFILES=	aclocal.m4

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|1.10|%%AUTOMAKE_APIVER%%|g' \
			  -e 's|2.61|%%AUTOCONF_VERSION%%|g' \
			  ${WRKSRC}/aclocal.m4
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/^dist_doc_DATA/d' ${WRKSRC}/Makefile.am
.endif

pre-configure:
.for f in ${AUTOFILES}
	@${RM} ${WRKSRC}/${f}
	@${LN} -s ${AUTOMAKE_DIR}/${f} ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
