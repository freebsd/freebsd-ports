# New ports collection Makefile for:	zile
# Date created:		28 September 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	zile
PORTVERSION=	2.4.8
CATEGORIES=	editors
MASTER_SITES=	GNU

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Small emacs-like text editor

LIB_DEPENDS=	gc:${PORTSDIR}/devel/boehm-gc
BUILD_DEPENDS=	${LOCALBASE}/bin/help2man:${PORTSDIR}/misc/help2man

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-regex

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME} \
		%%DOCSDIR%%/AUTHORS \
		%%DOCSDIR%%/FAQ \
		%%DOCSDIR%%/NEWS \
		%%DOCSDIR%%/dotzile.sample
PLIST_DIRS=	%%DOCSDIR%%

CPPFLAGS+=	-I${LOCALBASE}/include -isystem /usr/include/gnu
LDFLAGS+=	-L${LOCALBASE}/lib -lgnuregex

post-patch:
	@${REINPLACE_CMD} -e \
		'/need_charset_alias=/s|true|false|g' ${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e \
		's|@pkgdatadir@|${DOCSDIR}|' ${WRKSRC}/doc/man-extras

.include <bsd.port.mk>
