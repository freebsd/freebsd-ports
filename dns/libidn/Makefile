# New ports collection makefile for:	libidn
# Date created:        	19.06.2003
# Whom:               	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	libidn
PORTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/pub/gnu/${PORTNAME}/ \
		ftp://ftp.funet.fi/pub/mirrors/alpha.gnu.org/gnu/${PORTNAME}/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Internationalized Domain Names command line tool

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv
BUILD_DEPENDS=	gengetopt:${PORTSDIR}/devel/gengetopt

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GETOPT_LONG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if exists(${LOCALBASE}/bin/emacs)
PLIST_SUB+=	EMACS="" EMACSDIR=share/emacs
.elif exists(${LOCALBASE}/bin/xemacs)
PLIST_SUB+=	EMACS="" EMACSDIR=lib/xemacs
.else
PLIST_SUB+=	EMACS="@comment " EMACSDIR=""
.endif

MAN1=	idn.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README FAQ
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
