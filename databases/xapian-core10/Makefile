# New ports collection makefile for:	xapian-core10
# Date created:				5 November 2005
# Whom:					J.F. Dockes
#
# $FreeBSD$
#

PORTNAME=	xapian-core10
PORTVERSION=	1.0.23
CATEGORIES=	databases
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/
DISTNAME=	${PORTNAME:S/10$//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A probabilistic text search database engine

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS=	SSE2 "Use SSE2 for floating point" Off

MAN1=		quartzcheck.1 quartzcompact.1 quartzdump.1 \
		xapian-check.1 xapian-compact.1 xapian-config.1 \
		xapian-progsrv.1 xapian-tcpsrv.1 xapian-inspect.1

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/10$//}

.if defined(WITHOUT_SSE2)
CONFIGURE_ARGS+=	--disable-sse
.endif

post-install:
.for file in delve quest copydatabase
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/${file} ${PREFIX}/bin/xapian-${file}
.endfor
.ifdef(NOPORTDOCS)
	${RM} -rf ${DOCSDIR}
.endif

.include <bsd.port.mk>
