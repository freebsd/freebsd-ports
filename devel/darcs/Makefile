# New ports collection makefile for:	darcs
# Date created:				13 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darcs
PORTVERSION=	0.9.15
CATEGORIES=	devel
MASTER_SITES=	http://www.abridgegame.org/darcs/

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Yet another replacement for CVS, written in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_SIZE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${PREFIX}/lib/" \
		CFLAGS=""
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	darcs darcs.1

.if defined(WITH_SERVER)
ALL_TARGET+=	darcs_cgi darcs-createrepo
INSTALL_TARGET=	install installserver
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
.else
CGIDIR?=	www/cgi-bin
.endif
PLIST_SUB+=	CGIDIR=${CGIDIR} SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif

MAN1=	darcs.1

pre-everything::
.if !defined(WITH_SERVER)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "To build and install the server define WITH_SERVER."
	@${ECHO_CMD} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/doc/darcs|${DOCSDIR}|' \
		${WRKSRC}/darcsman.hs
.if defined(WITH_SERVER)
	@${REINPLACE_CMD} -e 's|$$(libexecdir)/cgi-bin|${PREFIX}/${CGIDIR}| ; \
		s|darcs/cgi.conf|cgi.conf.sample|' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e '/$$(sysconfdir)\/darcs/d' ${WRKSRC}/${MAKEFILE}
.endif
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/$$(datadir)/d' ${WRKSRC}/${MAKEFILE}
.else
	@${REINPLACE_CMD} -e 's|$$(datadir)/doc|${DOCSDIR}| ; /darcs\.ps/d' \
		${WRKSRC}/${MAKEFILE}
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|\(^CURLFLAGS.*\)|\1 -optl-pthread| \
		; s|all :.*|all::|' ${WRKSRC}/autoconf.mk

.include <bsd.port.mk>
