# New ports collection makefile for:	ksetispy
# Date created:		Sat Jan  5 14:44:45 BRST 2002
# Whom:		Hammurabi Mendes <hmendes@brturbo.com>
#
# $FreeBSD$
#

PORTNAME=	ksetispy
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hmendes@brturbo.com
COMMENT=	Monitors the progress of the SETI@home client

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

pre-everything::
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "===> Define WITH_OPTIMIZED_CFLAGS to enable additional compilation"
	@${ECHO_MSG} "===> optimizations."
.endif

post-patch:
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O2||' ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e 's/^(all:)[[:space:]]+docs-am/\1/; s/^(SUBDIRS.+)doc/\1/' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
