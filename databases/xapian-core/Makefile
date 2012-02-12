# New ports collection makefile for:	xapian-core
# Date created:				5 November 2005
# Whom:					J.F. Dockes
#
# $FreeBSD$
#

PORTNAME=	xapian-core
PORTVERSION=	1.2.8
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A probabilistic text search database engine

LICENSE=	GPLv2

OPTIONS=	SSE2	"Use SSE2 for floating point" off

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		xapian-check.1 \
		xapian-chert-update.1 \
		xapian-compact.1 \
		xapian-config.1 \
		xapian-inspect.1 \
		xapian-progsrv.1 \
		xapian-replicate.1 \
		xapian-replicate-server.1 \
		xapian-tcpsrv.1

.include <bsd.port.options.mk>

.if !defined(WITH_SSE2)
CONFIGURE_ARGS+=--disable-sse
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| docs||' ${WRKSRC}/Makefile.in
.endif

post-install:
.for file in delve quest copydatabase
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/${file} ${PREFIX}/bin/xapian-${file}
.endfor

.include <bsd.port.mk>
