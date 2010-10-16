# New ports collection makefile for:	dnswall
# Date created:				28 Jan 2008
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dnswall
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	dns security
MASTER_SITES=	GOOGLE_CODE CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A daemon that filters out private IP addresses in DNS responses

PROJECTHOST=	google-dnswall
USE_AUTOTOOLS=	automake:111
USE_DOS2UNIX=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

AUTOFILES=	depcomp install-sh missing

PORTDOCS=	README
PLIST_FILES=	bin/dnswall

post-patch:
	@${REINPLACE_CMD} -e 's|1.10|1.11.1|g' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|2.61|2.68|g' ${WRKSRC}/aclocal.m4
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^dist_doc_DATA/d' ${WRKSRC}/Makefile.am
.endif

pre-configure:
.for f in ${AUTOFILES}
	@${RM} ${WRKSRC}/${f}
	@${LN} ${AUTOMAKE_DIR}/${f} ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
