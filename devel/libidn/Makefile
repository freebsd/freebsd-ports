# New ports collection makefile for:	libidn
# Date created:        	19.06.2003
# Whom:               	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	libidn
PORTVERSION=	0.3.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA} \
		http://josefsson.org/libidn/releases/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Internationalized Domain Names command line tool

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv
BUILD_DEPENDS=	gengetopt:${PORTSDIR}/devel/gengetopt

USE_SIZE=	yes
USE_PERL5_BUILD=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
USE_GETOPT_LONG=	yes
USE_GNOME=	gnomehack
INFO=		libidn
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if exists(${LOCALBASE}/bin/emacs)
PLIST_SUB+=	EMACS="" EMACSDIR=share/emacs
.elif exists(${LOCALBASE}/bin/xemacs)
PLIST_SUB+=	EMACS="" EMACSDIR=lib/xemacs
.else
PLIST_SUB+=	EMACS="@comment " EMACSDIR=""
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README FAQ
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include "Makefile.man"
.include <bsd.port.mk>
