# New ports collection makefile for:	libiconv
# Date created:				17 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libiconv
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	converters devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org

USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libcharset/configure
CONFIGURE_ARGS=	--enable-static \
		--without-libintl-prefix
INSTALLS_SHLIB=	yes

MAN1=		iconv.1
MAN3=		iconv.3 iconv_open.3 iconv_close.3

.include <bsd.port.pre.mk>

# gperf 2.7.2 required
.if ${OSVERSION} < 430000
BUILD_DEPENDS=	${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf
GPERF=	${LOCALBASE}/bin/gperf
.else
GPERF=	/usr/bin/gperf
.endif

pre-build:
	@cd ${WRKSRC} ; ${GPERF} -t -L ANSI-C -H aliases_hash -N aliases_lookup -G -W aliases -7 -C -k '1,3-11,$$' -i 1 lib/aliases.gperf > lib/aliases.h

.include <bsd.port.post.mk>
