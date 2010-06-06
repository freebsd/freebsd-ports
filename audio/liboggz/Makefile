# New ports collection makefile for:	liboggz
# Date created:		08 October 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liboggz
DISTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/liboggz/ \
		http://wickedmachine.net/mirror/

MAINTAINER=	jsa@wickedmachine.net
COMMENT=	Simple Ogg API

LIB_DEPENDS=	ogg.7:${PORTSDIR}/audio/libogg

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ogg=${LOCALBASE} --program-transform-name=""
CONFIGURE_ENV=	HAVE_DOCBOOK2HTML=false DOCBOOKTOMAN=false HAVE_DOXYGEN=false HAVE_VALGRIND=false

MAN1=	oggz.1 \
	oggz-diff.1 \
	oggz-dump.1 \
	oggz-info.1 \
	oggz-known-codecs.1 \
	oggz-merge.1 \
	oggz-chop.1 \
	oggz-sort.1 \
	oggz-rip.1 \
	oggz-comment.1 \
	oggz-scan.1 \
	oggz-validate.1 \
	oggz-codecs.1

# First REINPLACE_CMD line makes all timestimes relative to localtime, crude hack
post-patch:
	@${REINPLACE_CMD} -e 's/timezone/0/' \
		${WRKSRC}/src/tools/oggz-chop/httpdate.c \
		${WRKSRC}/src/tools/oggz-chop/httpdate_test.c
	@${REINPLACE_CMD} -e '/^pkgconfigdir/s!=.*!= ${PREFIX}/libdata/pkgconfig!' \
		${WRKSRC}/Makefile.in
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} -e '/^install-data-am/s!install-data-local!!'	\
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
