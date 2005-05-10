# New ports collection makefile for:	iperf
# Date Created:				20 May 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	iperf
PORTVERSION=	2.0.2
CATEGORIES=	net ipv6
MASTER_SITES=	http://dast.nlanr.net/Projects/Iperf2.0/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	marcus@corp.grupos.com.br
COMMENT=	A tool to measure maximum TCP and UDP bandwidth

NO_CDROM=	"can't charge a fee for the software"

HAS_CONFIGURE=	yes

PLIST_FILES=	bin/iperf

OPTIONS=	IPV6	"Enable support to IPv6" 	on \
		THREADS	"Enable threads support"	on

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--prefix=${PREFIX}

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--disable-threads
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.for FILE in ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.gif
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
