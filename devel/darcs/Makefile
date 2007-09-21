# New ports collection makefile for:	darcs
# Date created:				13 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darcs
PORTVERSION=	1.0.9
CATEGORIES=	devel
MASTER_SITES=	http://darcs.net/

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Yet another replacement for CVS, written in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		gmp.7:${PORTSDIR}/math/libgmp4

OPTIONS=	SERVER "install server" on
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${PREFIX}/lib/ ${PTHREAD_LIBS}" \
		CFLAGS=""
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	darcs darcs.1
INSTALL_TARGET=	installbin

.include <bsd.port.pre.mk>

.if defined(WITH_SERVER)
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt
INSTALL_TARGET+=	installserver
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
.else
CGIDIR?=	www/cgi-bin
.endif
PLIST_SUB+=	CGIDIR=${CGIDIR} SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX-base
INSTALL_TARGET+=	installdocs
.endif

MAN1=	darcs.1

.if defined(WITH_SERVER)
post-patch:
	@${REINPLACE_CMD} -e 's|$$(libexecdir)/cgi-bin|${PREFIX}/${CGIDIR}| ; \
		s|darcs/cgi.conf|darcs/cgi.conf.sample|' \
		${WRKSRC}/${MAKEFILE}
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|$${prefix}|${PREFIX}|' ${WRKSRC}/cgi/darcs.cgi

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/darcs

.include <bsd.port.post.mk>
