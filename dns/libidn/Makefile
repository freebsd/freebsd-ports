# New ports collection makefile for:	libidn
# Date created:        	19.06.2003
# Whom:               	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	libidn
PORTVERSION=	0.5.15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA} \
		http://josefsson.org/libidn/releases/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Internationalized Domain Names command line tool

BUILD_DEPENDS=	gengetopt:${PORTSDIR}/devel/gengetopt

USE_GETOPT_LONG=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_ICONV=	yes
USE_LIBTOOL_VER=15
USE_PERL5_BUILD=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

INSTALLS_SHLIB=	yes

INFO=	libidn

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@image{components}||g' \
		${WRKSRC}/doc/libidn.texi

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README FAQ
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include "Makefile.man"
.include <bsd.port.mk>
