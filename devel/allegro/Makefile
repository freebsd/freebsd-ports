# New ports collection makefile for:	allegro
# Date created:		23-Feb-2001
# Whom:			Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	allegro
PORTVERSION=	4.0.2
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	alleg

MAINTAINER=	ports@FreeBSD.org

USE_AUTOCONF=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
INSTALLS_SHLIB=	yes

.if !defined (WITHOUT_DEVEL)
INSTALL_TARGET=	full-install
PLIST_SUB+=	FULL=""
.else
INSTALL_TARGET=	mini-install
PLIST_SUB+=	FULL="@comment "
.endif

CONFIGURE_ARGS+=	--enable-vga=no

.if !defined (WITHOUT_MAN)
INSTALL_TARGET+=	install-man
.endif

pre-build:
	cd ${WRKSRC} && ${GMAKE} depend

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/docs/html/* ${DOCSDIR}
.endif
	@${RM} -f ${LOCALBASE}/lib/liballeg.so.4.0
	@${MV} ${LOCALBASE}/lib/liballeg-${PORTVERSION}.so \
		${LOCALBASE}/lib/liballeg.so.4
	@${LN} -fs ${LOCALBASE}/lib/liballeg.so.4 ${LOCALBASE}/lib/liballeg.so
	@${MV} ${LOCALBASE}/lib/liballeg_unsharable.a \
		${LOCALBASE}/lib/liballeg.a
.if !defined (WITHOUT_MAN)
	@(cd ${WRKSRC}/docs/man ; ${FIND} *.3 | ${SED} "s|^|man/man3/|" \
		>> ${TMPPLIST})
.endif

.include <bsd.port.mk>
