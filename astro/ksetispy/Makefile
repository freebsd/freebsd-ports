# New ports collection makefile for:	ksetispy
# Date created:		Sat Jan  5 14:44:45 BRST 2002
# Whom:		Hammurabi Mendes <hmendes@brturbo.com>
#
# $FreeBSD$
#

PORTNAME=	ksetispy
PORTVERSION=	0.4.2
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hmendes@brturbo.com

USE_QT_VER=	2
USE_KDEBASE_VER=2

GNU_CONFIGURE=	yes

pre-everything::
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "===> Define WITH_OPTIMIZED_CFLAGS to enable additional compilation"
	@${ECHO_MSG} "===> optimizations."
.endif

post-patch:
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${PERL} -pi -e 's/-O2//' ${CONFIGURE_WRKSRC}/configure
.endif
.ifdef(NOPORTDOCS)
	@${PERL} -pi -e 's/^(all:) docs-am/\1/; s/^(SUBDIRS.+)?doc/\1/' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
