# New ports collection makefile for:	darcs
# Date created:				13 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darcs
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	http://darcs.net/

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Yet another replacement for CVS, written in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		gmp.6:${PORTSDIR}/math/libgmp4

OPTIONS=	SERVER "install server" off
USE_REINPLACE=	yes
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
ALL_TARGET+=	darcs-createrepo
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
INSTALL_TARGET+=	installdocs
.endif

MAN1=	darcs.1

post-patch:
.if defined(WITH_SERVER)
	@${REINPLACE_CMD} -e 's|$$(libexecdir)/cgi-bin|${PREFIX}/${CGIDIR}| ; \
		s|darcs/cgi.conf|cgi.conf.sample| ; /ln/d' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e '/$$(sysconfdir)\/darcs/d' ${WRKSRC}/${MAKEFILE}
.endif
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/$$(datadir)/d' ${WRKSRC}/${MAKEFILE}
.else
	@${REINPLACE_CMD} -e 's/^\(installdocs:.\)darcs.ps/\1/ ; \
			s/^\(installbin:\).*/\1/ ; /darcs\.ps/d ' \
		 ${WRKSRC}/${MAKEFILE}
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/darcs

.include <bsd.port.post.mk>
